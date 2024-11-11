#pragma once

#include "../Transport.h"

#include <stddef.h>

class LandTransport : public Transport {
public:
    class Rest {
    public:
        Rest(const double rests[], size_t size);
        const double& operator[](size_t index) const;
        ~Rest();

    private:
        size_t size;
        double* rests;
    };

    double getFinishTime(double distance) const override;
    virtual ~LandTransport();
protected:
    LandTransport(std::string name, double speed, double timeBeforeRest,
            const double rests[], size_t size);
    Rest rest;
    double timeBeforeRest;
};
