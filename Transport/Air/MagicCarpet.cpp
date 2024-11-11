#include "MagicCarpet.h"
#include "Consts.h"

MagicCarpet::MagicCarpet() 
    : AirTransport(
        Consts::magicCarpetName,
        Consts::magicCarpetSpeed
    ) {}

double MagicCarpet::getDistance(double distance) const {
    if (distance < 1000) {
        return distance;
    } else if (distance < 5000) {
        return distance * 0.97;
    } else if (distance < 10000) {
        return distance * 0.9;
    } else {
        return distance * 0.95;
    }
}

