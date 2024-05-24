#ifndef PASSMANAGER_H
#define PASSMANAGER_H

#include "IPassManager.h"
#include <unordered_map>
#include <ctime>

class Pass {
public:
    int id;
    std::string user_name;
    bool is_temporary;
    time_t valid_until;

    Pass(int id, const std::string& user_name, bool is_temporary = false, time_t valid_until = 0)
        : id(id), user_name(user_name), is_temporary(is_temporary), valid_until(valid_until) {}

    bool isValid() const {
        if (is_temporary && time(nullptr) > valid_until) {
            return false;
        }
        return true;
    }
};

class PassManager : public IPassManager {
private:
    std::unordered_map<int, Pass> passes;

public:
    void issuePass(int id, const std::string& user_name, bool is_temporary = false, time_t valid_until = 0) override {
        passes[id] = Pass(id, user_name, is_temporary, valid_until);
    }

    void revokePass(int id) override {
        passes.erase(id);
    }

    bool checkPass(int id) override {
        return passes.find(id) != passes.end() && passes[id].isValid();
    }
};

#endif 
