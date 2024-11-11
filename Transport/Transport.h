#pragma once

#include <string>

class Transport {
public:
    enum class Kind {
        land,
        air
    };
    std::string getName() const;
    Kind getKind() const;
    virtual double getFinishTime(double distance) const = 0;
    virtual ~Transport();
protected:
    Transport(Kind kind, std::string name, double speed);
    Kind kind;
    std::string name;
    double speed;
};
