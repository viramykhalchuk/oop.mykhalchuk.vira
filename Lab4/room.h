#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Turnstile.h"

class Room {
public:
    Room(const std::string& id);
    std::string getId() const;
    void addTurnstile(Turnstile* turnstile);
    std::vector<Turnstile*> getTurnstiles() const;

private:
    std::string id;
    std::vector<Turnstile*> turnstiles;
};

#endif 
