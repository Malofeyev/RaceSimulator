#include "FastCamel.h"

#include "Consts.h"

FastCamel::FastCamel() 
    : LandTransport(
        Consts::fastCamelName,
        Consts::fastCamelSpeed,
        Consts::fastCamelTimeBeforeRest,
        Consts::fastCamelRests,
        Consts::fastCamelRestsSize
    ) {}

