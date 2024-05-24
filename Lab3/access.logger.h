#ifndef ACCESSLOGGER_H
#define ACCESSLOGGER_H

#include "IAccessLogger.h"
#include <vector>
#include <iostream>
#include <ctime>

class AccessLog {
public:
    time_t timestamp;
    int pass_id;
    std::string entry_or_exit;

    AccessLog(int pass_id, const std::string& entry_or_exit)
        : pass_id(pass_id), entry_or_exit(entry_or_exit) {
        timestamp = time(nullptr);
    }
};

class AccessLogger : public IAccessLogger {
private:
    std::vector<AccessLog> logs;

public:
    void logEntry(int pass_id) override {
        logs.push_back(AccessLog(pass_id, "entry"));
    }

    void logExit(int pass_id) override {
        logs.push_back(AccessLog(pass_id, "exit"));
    }

    void getStatistics() override {
        for (const auto& log : logs) {
            std::cout << "Pass ID: " << log.pass_id << ", Action: " << log.entry_or_exit << ", Timestamp: " << ctime(&log.timestamp);
        }
    }
};

#endif 
