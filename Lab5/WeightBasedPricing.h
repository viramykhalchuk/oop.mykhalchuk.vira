#pragma once
#include "Product.h"

class WeightBasedPricing : public PriceStrategy {
private:
    double pricePerKg;
public:
    WeightBasedPricing(double pricePerKg) : pricePerKg(pricePerKg) {}

    double calculatePrice(double weight) const override {
        return weight * pricePerKg;
    }
};
