#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include <unordered_map>
#include "Room.h"

class AccessControlSystem {
public:
    AccessControlSystem();
    bool openTurnstile(const std::string& roomId, Turnstile& turnstile, const std::string& passId);
    Pass* issuePass(const std::string& id, std::chrono::system_clock::time_point expiry, const std::string& roomId);
    void revokePass(const std::string& id);
    void addRoom(Room* room);

private:
    std::unordered_map<std::string, Pass*> passes;
    std::unordered_map<std::string, Room*> rooms;
};

#endif 
