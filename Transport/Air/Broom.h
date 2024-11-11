#pragma once

#include "AirTransport.h"

class Broom : public AirTransport {
public:
    Broom();
private:
    double getDistance(double distance) const override;
};

