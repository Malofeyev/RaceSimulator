#include "Game.h"

#include "Consts.h"

#include <Transport/Transport.h>
#include <Transport/Land/AllTerrainBoots.h>
#include <Transport/Land/Camel.h>
#include <Transport/Land/Centaur.h>
#include <Transport/Land/FastCamel.h>
#include <Transport/Air/Broom.h>
#include <Transport/Air/Eagle.h>
#include <Transport/Air/MagicCarpet.h>

#include <algorithm>
#include <format>
#include <stdexcept>

enum class TransportNum {
    boots = 0,
    broom,
    camel,
    centaur,
    eagle,
    fastCamel,
    carpet
};

const static AllTerrainBoots boots;
const static Broom broom;
const static Camel camel;
const static Centaur centaur;
const static Eagle eagle;
const static FastCamel fastCamel;
const static MagicCarpet carpet;

struct OutputTransport {
    std::string name;
    double time;
    bool operator<(const OutputTransport& other) {
        return this->time < other.time;
    }
};

Game::Game() : currentStep(Step::start) {
    transports[static_cast<int>(TransportNum::boots)].transport = &boots;
    transports[static_cast<int>(TransportNum::broom)].transport = &broom;
    transports[static_cast<int>(TransportNum::camel)].transport = &camel;
    transports[static_cast<int>(TransportNum::centaur)].transport = &centaur;
    transports[static_cast<int>(TransportNum::eagle)].transport = &eagle;
    transports[static_cast<int>(TransportNum::fastCamel)].transport = &fastCamel;
    transports[static_cast<int>(TransportNum::carpet)].transport = &carpet;
}

Game::Response Game::start() {
    assertRightStep(Step::start);

    reset();

    return {true, Consts::startMsg + Consts::raceTypeListMsg};
}

Game::Response Game::chooseRaceType(int type) {
    assertRightStep(Step::raceType);
    if (type > 0 && type < 4) {
        raceType = static_cast<Game::RaceType>(type - 1);
        switch (raceType) {
            case RaceType::land:
                raceTypeMsg = Consts::landMsg;
                break;
            case RaceType::air:
                raceTypeMsg = Consts::airMsg;
                break;
            case RaceType::common:
                raceTypeMsg = Consts::landAirMsg;
                break;
        }
        currentStep = Step::distance;
        return {true, Consts::distanceMsg};
    } else {
        return {false, Consts::raceTypeErr + Consts::raceTypeListMsg};
    }

}

Game::Response Game::chooseDistance(double distance) {
    assertRightStep(Step::distance);
    if (distance > 0) {
        this->distance = distance;
        transportListPrefixMsg = std::format(
                Consts::transportListPrefixTemplate, 
                raceTypeMsg, distance);
        currentStep = Step::requirement2transports;
        return {true, Consts::transportMsg};
    } else {
        return {false, Consts::distanceErr + Consts::distanceMsg};
    }
}

Game::Response Game::require2Transports(int one) {
    assertRightStep(Step::requirement2transports);
    if (one == 1) {
        currentStep = Step::registration;
        return {true, getTransportListMsg()};
    } else {
        return {false, Consts::actionErr + Consts::transportMsg};
    }
}

Game::Response Game::registrateTransport(int action) {
    assertRightStep(Step::registration);
    if (action == 0) {
        int countParticipant = 0;
        for (int i = 0; i < countTransport; i++) {
            if (transports[i].hasRegistration) {
                countParticipant++;
            }
        }

        if (countParticipant < 2) {
            currentStep = Step::requirement2transports;
            return {false, Consts::transportMsg};
        } else {
            currentStep = Step::race;
            return {true, Consts::registrationOrStartMsg};
        }
    } else if (action > 0 && action <= countTransport) {
        Transport::Kind kind = transports[action - 1].transport->getKind();
        if (raceType != RaceType::common && (
                (raceType == RaceType::land && kind != Transport::Kind::land) || 
                (raceType == RaceType::air && kind != Transport::Kind::air))) {
            return {false, Consts::transportTypeErr + getTransportListMsg()};
        } if (transports[action - 1].hasRegistration) {
            return {
                false,
                std::format(
                        Consts::alreadyHasRegistrationTemplate, 
                        transports[action - 1].transport->getName()
                        ) + getTransportListMsg()
            };
        } else {
            transports[action - 1].hasRegistration = true;
            return {
                true, 
                std::format(Consts::successfulRegistrationTemplate, 
                        transports[action - 1].transport->getName()
                        ) + getTransportListMsg()
            };
        }
    } else {
        return {false, Consts::actionErr + getTransportListMsg()};
    }
}

Game::Response Game::startRace(int action) {
    assertRightStep(Step::race);
    if (action == 1) {
        currentStep = Step::registration;
        return {true, getTransportListMsg()};
    } else if (action == 2) {
        currentStep = Step::finish;
        std::string result = Consts::resultPrefixMsg;
        
        int countRegistratedTransport = 0;
        OutputTransport outputTransports[countTransport];
        for (int i = 0; i < countTransport; i++) {
            if (transports[i].hasRegistration) {
                outputTransports[countRegistratedTransport] = {
                   transports[i].transport->getName(),
                   transports[i].transport->getFinishTime(distance) 
                };
                countRegistratedTransport++;
            }
        }
        std::sort(outputTransports, 
                outputTransports + countRegistratedTransport);
        for (int i = 0; i < countRegistratedTransport; i++) {
            result += std::format(Consts::placeTemplate, 
                    i + 1, outputTransports[i].name, outputTransports[i].time);
        }
        return {true, result + "\n" + Consts::startOrQuitMsg};
    } else {
        return {false, Consts::actionErr + Consts::registrationOrStartMsg};
    }

}

Game::Response Game::finish(int action) {
    assertRightStep(Step::finish);
    if (action == 1) {
        reset();
        return {true, Consts::raceTypeListMsg};
    } if (action == 2) {
        currentStep = Step::termination;
        return {true, ""};
    } else {
        return {false, Consts::actionErr};
    }
}

bool Game::isTerminated() const {
    return currentStep == Step::termination;
}

void Game::assertRightStep(Step step) const {
    if (step != currentStep) {
        throw std::invalid_argument(std::format(
                    "\nActual step: {}\nExpected step: {}\n",
                    static_cast<int>(currentStep), 
                    static_cast<int>(step)));
    }
}

std::string Game::getTransportListMsg() const {
    int i = 0;
    while (i < 7) {
        if (transports[i].hasRegistration) {
            break;
        }
        i++;
    }
    if (i < 7) {
        std::string registratedTransportListMsg = 
            Consts::registratedTransportListPrefix;
        registratedTransportListMsg += 
            transports[i].transport->getName();
        i++;
        while (i < countTransport) {
            if (transports[i].hasRegistration) {
                registratedTransportListMsg += 
                    ", " + transports[i].transport->getName();
            }
            i++;
        }
        registratedTransportListMsg += "\n";
        return transportListPrefixMsg + 
            registratedTransportListMsg + 
            Consts::transportListMsg;
    } else {
        return transportListPrefixMsg + Consts::transportListMsg;
    }
}

void Game::reset() {

    currentStep = Step::raceType;

    transports[static_cast<int>(TransportNum::boots)].hasRegistration = false;
    transports[static_cast<int>(TransportNum::broom)].hasRegistration = false;
    transports[static_cast<int>(TransportNum::camel)].hasRegistration = false;
    transports[static_cast<int>(TransportNum::centaur)].hasRegistration = false;
    transports[static_cast<int>(TransportNum::eagle)].hasRegistration = false;
    transports[static_cast<int>(TransportNum::fastCamel)].hasRegistration = false;
    transports[static_cast<int>(TransportNum::carpet)].hasRegistration = false;
}

