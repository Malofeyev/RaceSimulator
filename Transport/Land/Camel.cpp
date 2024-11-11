#include "Camel.h"

#include "Consts.h"

Camel::Camel() 
    : LandTransport(Consts::camelName, 
            Consts::camelSpeed, 
            Consts::camelTimeBeforeRest, 
            Consts::camelRests, 
            Consts::camelRestsSize) {}

