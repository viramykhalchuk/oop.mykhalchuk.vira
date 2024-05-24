#ifndef IPASSMANAGER_H
#define IPASSMANAGER_H

#include <string>
#include <ctime>

class IPassManager {
public:
    virtual ~IPassManager() = default;
    virtual void issuePass(int id, const std::string& user_name, bool is_temporary = false, time_t valid_until = 0) = 0;
    virtual void revokePass(int id) = 0;
    virtual bool checkPass(int id) = 0;
};

#endif
