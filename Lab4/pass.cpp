#include "Pass.h"

Pass::Pass(const std::string& id, std::chrono::system_clock::time_point expiry, const std::string& roomId)
    : id(id), expiry(expiry), roomId(roomId) {}

bool Pass::isExpired() const {
    return std::chrono::system_clock::now() > expiry;
}

std::string Pass::getId() const {
    return id;
}

std::string Pass::getRoomId() const {
    return roomId;
}
