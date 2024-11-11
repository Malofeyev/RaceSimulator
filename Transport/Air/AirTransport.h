#pragma once

#include "../Transport.h"

#include <string>

class AirTransport : public Transport {
protected:
    AirTransport(std::string name, double speed);
    virtual double getDistance(double distance) const = 0;
public:
    double getFinishTime(double distance) const override;
    virtual ~AirTransport();
};


