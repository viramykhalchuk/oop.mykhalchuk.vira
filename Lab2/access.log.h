#ifndef ACCESSLOG_H
#define ACCESSLOG_H

#include <ctime>
#include <string>

class AccessLog {
public:
    time_t timestamp;
    int pass_id;
    std::string entry_or_exit;

    AccessLog(int pass_id, std::string entry_or_exit);
};

#endif 
