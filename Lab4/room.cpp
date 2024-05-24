#include "Room.h"

Room::Room(const std::string& id) : id(id) {}

std::string Room::getId() const {
    return id;
}

void Room::addTurnstile(Turnstile* turnstile) {
    turnstiles.push_back(turnstile);
}

std::vector<Turnstile*> Room::getTurnstiles() const {
    return turnstiles;
}
