#include <boost/di.hpp>
#include "IPassManager.h"
#include "IAccessLogger.h"
#include "IAccessControlSystem.h"
#include "PassManager.h"
#include "AccessLogger.h"
#include "AccessControlSystem.h"

namespace di = boost::di;

int main() {
    // Configure the DI container
    auto injector = di::make_injector(
        di::bind<IPassManager>().to<PassManager>(),
        di::bind<IAccessLogger>().to<AccessLogger>(),
        di::bind<IAccessControlSystem>().to<AccessControlSystem>()
    );

    // Create the AccessControlSystem using the DI container
    auto acs = injector.create<std::shared_ptr<IAccessControlSystem>>();

    // Issue passes
    auto passManager = injector.create<std::shared_ptr<IPassManager>>();
    passManager->issuePass(1, "Alice", false);
    passManager->issuePass(2, "Bob", true, time(nullptr) + 3600); // Valid for 1 hour

    // Log entries and exits
    acs->entry(1);
    acs->exit(1);

    acs->entry(2);
    acs->exit(2);

    // Retrieve statistics
    auto accessLogger = injector.create<std::shared_ptr<IAccessLogger>>();
    accessLogger->getStatistics();

    // Revoke passes
    passManager->revokePass(1);
    passManager->revokePass(2);

    return 0;
}
