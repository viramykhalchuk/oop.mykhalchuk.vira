#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include "BST.h"
#include "AccessLog.h"
#include <vector>
#include <iostream>

class AccessControlSystem {
private:
    BST passTree;
    std::vector<AccessLog> logs;

public:
    void issuePass(Pass pass);
    void revokePass(int pass_id);
    bool checkPass(int pass_id);
    void logEntry(int pass_id);
    void logExit(int pass_id);
    void getStatistics();
};

#endif 
