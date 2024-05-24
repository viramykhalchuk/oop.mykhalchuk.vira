#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include "Pass.h"
#include <vector>

class AccessControlSystem {
private:
    vector<Pass*> passes;

public:
    ~AccessControlSystem() {
        for (auto pass : passes) {
            delete pass;
        }
    }

    void addPass(Pass* pass) {
        passes.push_back(pass);
    }

    void printAllPassesInfo() const {
        for (const auto& pass : passes) {
            pass->printInfo();
        }
    }

    void checkAllPassesValidity() const {
        for (const auto& pass : passes) {
            if (pass->isValid()) {
                cout << "Pass with ID: " << pass->id << " is valid." << endl;
            } else {
                cout << "Pass with ID: " << pass->id << " is invalid." << endl;
            }
        }
    }
};

#endif
