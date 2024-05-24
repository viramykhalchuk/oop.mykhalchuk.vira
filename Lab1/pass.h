#ifndef PASS_H
#define PASS_H

#include <iostream>
#include <string>

using namespace std;

class Pass {
protected:
    string name;

public:
    string id;
    Pass(const string& name, const string& id) : name(name), id(id) {}
    virtual ~Pass() {}
    virtual bool isValid() const = 0;
    virtual void printInfo() const = 0;
};

#endif
