#pragma once
#include <unordered_map>
#include <functional>
#include <string>

class IoCContainer {
private:
    std::unordered_map<std::string, std::function<void*()>> factories;
public:
    template<typename T>
    void registerFactory(const std::string& key, std::function<T*()> factory) {
        factories[key] = [factory]() { return static_cast<void*>(factory()); };
    }

    template<typename T>
    T* resolve(const std::string& key) {
        auto it = factories.find(key);
        if (it != factories.end()) {
            return static_cast<T*>(it->second());
        }
        throw std::runtime_error("No factory registered for key " + key);
    }
};
