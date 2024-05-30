#pragma once
#include <string>

class PriceStrategy {
public:
    virtual double calculatePrice(double weight) const = 0;
    virtual ~PriceStrategy() = default;
};

class Product {
protected:
    std::string name;
    double weight;
    PriceStrategy* priceStrategy;
public:
    Product(const std::string& name, double weight, PriceStrategy* priceStrategy)
        : name(name), weight(weight), priceStrategy(priceStrategy) {}

    double getPrice() const {
        return priceStrategy->calculatePrice(weight);
    }

    std::string getName() const {
        return name;
    }

    double getWeight() const {
        return weight;
    }
};
