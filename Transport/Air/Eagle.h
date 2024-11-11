#pragma once

#include "AirTransport.h"

class Eagle : public AirTransport {
public:
    Eagle();
private:
    double getDistance(double distance) const override;
};

