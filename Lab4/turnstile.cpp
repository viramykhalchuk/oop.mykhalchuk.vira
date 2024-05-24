#include "Turnstile.h"

Turnstile::Turnstile() {}

bool Turnstile::passThrough(Pass* pass) {
    if (pass && !pass->isExpired()) {
        recordEntry(pass->getId());
        return true;
    }
    return false;
}

void Turnstile::recordEntry(const std::string& passId) {
    if (entries.find(passId) != entries.end()) {
        entries[passId]++;
    } else {
        entries[passId] = 1;
    }
}
