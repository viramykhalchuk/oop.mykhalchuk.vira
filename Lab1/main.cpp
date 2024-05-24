#include "TemporaryPass.h"
#include "AccessControlSystem.h"

int main() {
    AccessControlSystem system;

    system.addPass(new TemporaryPass("Biront Lida", "7778", "06.10.2024"));
    system.addPass(new TemporaryPass("Mykhalchuk Ivan", "4838", "10.07.2023"));

    system.printAllPassesInfo();
    system.checkAllPassesValidity();

    return 0;
}
