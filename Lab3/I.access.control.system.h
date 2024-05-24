#ifndef IACCESSCONTROLSYSTEM_H
#define IACCESSCONTROLSYSTEM_H

class IAccessControlSystem {
public:
    virtual ~IAccessControlSystem() = default;
    virtual void entry(int pass_id) = 0;
    virtual void exit(int pass_id) = 0;
};

#endif 
