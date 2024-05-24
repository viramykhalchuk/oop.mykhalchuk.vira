#ifndef TURNSTILE_H
#define TURNSTILE_H

#include <unordered_map>
#include "Pass.h"

class Turnstile {
public:
    Turnstile();
    bool passThrough(Pass* pass);
    void recordEntry(const std::string& passId);

private:
    std::unordered_map<std::string, int> entries;
};

#endif 
