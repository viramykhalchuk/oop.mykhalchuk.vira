#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include "IAccessControlSystem.h"
#include "IPassManager.h"
#include "IAccessLogger.h"
#include <memory>

using namespace std;

class AccessControlSystem : public IAccessControlSystem {
private:
    std::shared_ptr<IPassManager> passManager;
    std::shared_ptr<IAccessLogger> accessLogger;

public:
    AccessControlSystem(std::shared_ptr<IPassManager> pm, std::shared_ptr<IAccessLogger> al)
        : passManager(pm), accessLogger(al) {}

    void entry(int pass_id) override {
        if (passManager->checkPass(pass_id)) {
            accessLogger->logEntry(pass_id);
        } else {
            cerr << "Invalid pass ID: " << pass_id << endl;
        }
    }

    void exit(int pass_id) override {
        if (passManager->checkPass(pass_id)) {
            accessLogger->logExit(pass_id);
        } else {
            cerr << "Invalid pass ID: " << pass_id << endl;
        }
    }
};

#endif
