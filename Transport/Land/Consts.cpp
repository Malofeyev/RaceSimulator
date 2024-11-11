#include "Consts.h"

namespace Consts {
    
    const char* allTerrainBootsName = "Ботинки-вездеходы";
    const double allTerrainBootsSpeed = 6;
    const double allTerrainBootsTimeBeforeRest = 60;
    const size_t allTerrainBootsRestsSize = 2;
    const double allTerrainBootsRests[allTerrainBootsRestsSize] = {10, 5};


    const char* camelName = "Верблюд";
    const double camelSpeed = 10;
    const double camelTimeBeforeRest = 30;
    const size_t camelRestsSize = 2;
    const double camelRests[camelRestsSize] = {5, 8};


    const char* centaurName = "Кентавр";
    const double centaurSpeed = 15;
    const double centaurTimeBeforeRest = 8;
    const size_t centaurRestsSize = 1;
    const double centaurRests[centaurRestsSize] = {2};


    const char* fastCamelName = "Верблюд-быстроход";
    const double fastCamelSpeed = 40;
    const double fastCamelTimeBeforeRest = 10;
    const size_t fastCamelRestsSize = 3;
    const double fastCamelRests[fastCamelRestsSize] = {5, 6.5, 8};
}
