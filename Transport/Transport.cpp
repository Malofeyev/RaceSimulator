#include "Transport.h"

Transport::Transport(Kind kind, std::string name, double speed)
    : kind(kind), name(std::move(name)), speed(speed) {}

std::string Transport::getName() const {
    return name;
}

Transport::Kind Transport::getKind() const {
    return kind;
}

Transport::~Transport() = default;

