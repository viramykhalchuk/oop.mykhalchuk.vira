#include "Pass.h"

Pass::Pass(int id, std::string user_name, bool is_temporary, time_t valid_until)
    : id(id), user_name(user_name), is_temporary(is_temporary), valid_until(valid_until) {}

bool Pass::isValid() {
    if (is_temporary && time(nullptr) > valid_until) {
        return false;
    }
    return true;
}
