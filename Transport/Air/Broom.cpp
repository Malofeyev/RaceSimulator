#include "Broom.h"
#include "Consts.h"

Broom::Broom() 
    : AirTransport(
        Consts::broomName,
        Consts::broomSpeed
    ) {}

double Broom::getDistance(double distance) const {
    return distance -
        static_cast<int>(distance) / 1000 / 100.0 * distance;
}

