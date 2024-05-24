#ifndef IACCESSLOGGER_H
#define IACCESSLOGGER_H

class IAccessLogger {
public:
    virtual ~IAccessLogger() = default;
    virtual void logEntry(int pass_id) = 0;
    virtual void logExit(int pass_id) = 0;
    virtual void getStatistics() = 0;
};

#endif 
