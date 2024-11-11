#include "LandTransport.h"

LandTransport::Rest::Rest(const double rests[], 
        size_t size) : size(size) {
    this->rests = new double[size];
    for (int i = 0; i < size; i++) {
        this->rests[i] = rests[i];
    }
}

const double& LandTransport::Rest::operator[](size_t index) const {
    if (index >= size) {
        return this->rests[size - 1];
    } else {
        return this->rests[index];
    }
}

LandTransport::Rest::~Rest() {
    delete[] rests;
}

LandTransport::LandTransport(std::string name, double speed, 
        double timeBeforeRest,
        const double rests[], size_t size)        
    : Transport(Transport::Kind::land, std::move(name), speed)
    , timeBeforeRest(timeBeforeRest)
    , rest(rests, size) {}

double LandTransport::getFinishTime(double distance) const {
    double time = 0;
    int i = 0;
    while (distance - speed * timeBeforeRest > 0) {
        time += timeBeforeRest;
        distance -= speed * timeBeforeRest;
        
        time += rest[i];
        i++;
    }

    time += distance / speed;
    return time;
}

LandTransport::~LandTransport() = default;
