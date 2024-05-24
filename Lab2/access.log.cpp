#include "AccessLog.h"

AccessLog::AccessLog(int pass_id, std::string entry_or_exit)
    : pass_id(pass_id), entry_or_exit(entry_or_exit) {
    timestamp = time(nullptr);
}
