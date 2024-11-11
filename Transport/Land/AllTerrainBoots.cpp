#include "AllTerrainBoots.h"

#include "Consts.h"

AllTerrainBoots::AllTerrainBoots() 
    : LandTransport(Consts::allTerrainBootsName, 
            Consts::allTerrainBootsSpeed, 
            Consts::allTerrainBootsTimeBeforeRest,
            Consts::allTerrainBootsRests, 
            Consts::allTerrainBootsRestsSize) {}
