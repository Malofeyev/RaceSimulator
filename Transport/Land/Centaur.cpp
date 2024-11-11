#include "Centaur.h"

#include "Consts.h"

Centaur::Centaur() 
    : LandTransport(
        Consts::centaurName,
        Consts::centaurSpeed,
        Consts::centaurTimeBeforeRest,
        Consts::centaurRests,
        Consts::centaurRestsSize
    ) {}

