#ifndef TEMPORARYPASS_H
#define TEMPORARYPASS_H

#include "Pass.h"
#include <ctime>
#include <sstream>

class TemporaryPass : public Pass {
private:
    string expirationDate;

public:
    TemporaryPass(const string& name, const string& id, const string& expirationDate)
        : Pass(name, id), expirationDate(expirationDate) {}

    bool isValid() const override {
        time_t currentTime = time(nullptr);
        tm* currentDate = localtime(&currentTime);

        tm expiration = {};
        istringstream ss(expirationDate);

        int day, month, year;
        char delimiter;
        ss >> day >> delimiter >> month >> delimiter >> year;

        expiration.tm_mday = day;
        expiration.tm_mon = month - 1;
        expiration.tm_year = year - 1900;

        if (difftime(mktime(currentDate), mktime(&expiration)) > 0) {
            return false;
        } else {
            return true;
        }
    }

    void printInfo() const override {
        cout << "Temporary Pass - Name: " << name << ", ID: " << id << ", Expiration Date: " << expirationDate << endl;
    }
};

#endif
