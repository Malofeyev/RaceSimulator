#pragma once

#include "AirTransport.h"

class MagicCarpet : public AirTransport {
public:
    MagicCarpet();
private:
    double getDistance(double distance) const override;
};

