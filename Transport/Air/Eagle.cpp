#include "Eagle.h"
#include "Consts.h"

Eagle::Eagle() 
    : AirTransport(
        Consts::eagleName,
        Consts::eagleSpeed
    ) {}

double Eagle::getDistance(double distance) const {
    return distance * 0.94;
}

