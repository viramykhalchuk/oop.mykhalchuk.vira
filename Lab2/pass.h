#ifndef PASS_H
#define PASS_H

#include <string>
#include <ctime>

class Pass {
public:
    int id;
    std::string user_name;
    bool is_temporary;
    time_t valid_until;

    Pass(int id, std::string user_name, bool is_temporary = false, time_t valid_until = 0);

    bool isValid();
};

#endif 
