#include "AccessControlSystem.h"

int main() {
    AccessControlSystem acs;

    Pass pass1(1, "Lida", false);
    Pass pass2(2, "Ivan", true, time(nullptr) + 3600); // Valid for 1 hour

    acs.issuePass(pass1);
    acs.issuePass(pass2);

    acs.logEntry(1);
    acs.logExit(1);

    acs.logEntry(2);
    acs.logExit(2);

    acs.getStatistics();

    acs.revokePass(1);
    acs.revokePass(2);

    return 0;
}
