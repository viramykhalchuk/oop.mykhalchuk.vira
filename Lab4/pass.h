#ifndef PASS_H
#define PASS_H

#include <string>
#include <chrono>

class Pass {
public:
    Pass(const std::string& id, std::chrono::system_clock::time_point expiry, const std::string& roomId);
    bool isExpired() const;
    std::string getId() const;
    std::string getRoomId() const;

private:
    std::string id;
    std::chrono::system_clock::time_point expiry;
    std::string roomId;
};

#endif 

