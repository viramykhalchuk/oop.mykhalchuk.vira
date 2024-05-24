#include "AccessControlSystem.h"

AccessControlSystem::AccessControlSystem() {}

bool AccessControlSystem::openTurnstile(const std::string& roomId, Turnstile& turnstile, const std::string& passId) {
    Pass* pass = nullptr;
    auto it = passes.find(passId);
    if (it != passes.end()) {
        pass = it->second;
    }
    if (pass && pass->getRoomId() == roomId) {
        return turnstile.passThrough(pass);
    }
    return false;
}

Pass* AccessControlSystem::issuePass(const std::string& id, std::chrono::system_clock::time_point expiry, const std::string& roomId) {
    Pass* pass = new Pass(id, expiry, roomId);
    passes[id] = pass;
    return pass;
}

void AccessControlSystem::revokePass(const std::string& id) {
    auto it = passes.find(id);
    if (it != passes.end()) {
        delete it->second;
        passes.erase(it);
    }
}

void AccessControlSystem::addRoom(Room* room) {
    rooms[room->getId()] = room;
}
