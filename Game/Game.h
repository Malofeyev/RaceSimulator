#pragma once

#if defined(_WIN32)
#   if defined(EXPORTING_GAME)
#       define DECLSPEC __declspec(dllexport)
#   else
#       define DECLSPEC __declspec(dllimport)
#   endif
#else
#   define DECLSPEC 
#endif

#include <string>

class Transport;

class DECLSPEC Game {
public:

    enum class RaceType {
        land,
        air,
        common
    };

    enum class Step {
        start,
        raceType,
        distance,
        requirement2transports,
        registration,
        race,
        finish,
        termination
    };

    struct Response {
        bool result;
        std::string message;
    };

    Game();

    Response start();
    Response chooseRaceType(int type);
    Response chooseDistance(double distance);
    Response require2Transports(int one);
    Response registrateTransport(int action);
    Response startRace(int action);
    Response finish(int action);
    bool isTerminated() const;


private:
    
    constexpr static size_t countTransport = 7;
    

    RaceType raceType;
    std::string raceTypeMsg;
    double distance;
    std::string transportListPrefixMsg;

    struct Participant {
        const Transport* transport;
        bool hasRegistration;
    };

    Participant transports[countTransport];
    Step currentStep;

    void assertRightStep(Step step) const;
    std::string getTransportListMsg() const;
    void reset();

};
