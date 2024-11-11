#include "AirTransport.h"

AirTransport::AirTransport(std::string name, double speed) 
    : Transport(Transport::Kind::air, std::move(name), speed) {}

double AirTransport::getFinishTime(double distance) const {
    return getDistance(distance) / speed;
}

AirTransport::~AirTransport() = default;

