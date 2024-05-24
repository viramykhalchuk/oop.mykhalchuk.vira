#include "AccessControlSystem.h"

void AccessControlSystem::issuePass(Pass pass) {
    passTree.insert(pass);
}

void AccessControlSystem::revokePass(int pass_id) {
    passTree.deleteNode(pass_id);
}

bool AccessControlSystem::checkPass(int pass_id) {
    Pass* pass = passTree.search(pass_id);
    return pass != nullptr && pass->isValid();
}

void AccessControlSystem::logEntry(int pass_id) {
    if (checkPass(pass_id)) {
        logs.push_back(AccessLog(pass_id, "entry"));
    } else {
        std::cerr << "Invalid pass ID: " << pass_id << std::endl;
    }
}

void AccessControlSystem::logExit(int pass_id) {
    if (checkPass(pass_id)) {
        logs.push_back(AccessLog(pass_id, "exit"));
    } else {
        std::cerr << "Invalid pass ID: " << pass_id << std::endl;
    }
}

void AccessControlSystem::getStatistics() {
    for (const auto& log : logs) {
        std::cout << "Pass ID: " << log.pass_id << ", Action: " << log.entry_or_exit << ", Timestamp: " << ctime(&log.timestamp);
    }
}
