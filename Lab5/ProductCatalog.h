#pragma once
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "Product.h"
#include "IoCContainer.h"
#include "WeightBasedPricing.h"

class ProductCatalog {
private:
    std::unordered_map<std::string, PriceStrategy*> products;
    IoCContainer& container;
    const std::string filename = "products.txt";

public:
    ProductCatalog(IoCContainer& container) : container(container) {
        loadProducts();
    }

    ~ProductCatalog() {
        saveProducts();
        for (auto& product : products) {
            delete product.second;
        }
    }

    void addProduct(const std::string& name, double pricePerKg) {
        PriceStrategy* strategy = new WeightBasedPricing(pricePerKg);
        products[name] = strategy;
        container.registerFactory<PriceStrategy>(name, [strategy]() { return strategy; });
    }

    void listProducts() {
        std::cout << "Available products: ";
        for (const auto& product : products) {
            std::cout << product.first << "; ";
        }
        std::cout << std::endl;
    }

    void printProducts() {
        std::cout << "Available products:" << std::endl;
        for (const auto& product : products) {
            WeightBasedPricing* strategy = dynamic_cast<WeightBasedPricing*>(product.second);
            if (strategy) {
                std::cout << "Product: " << product.first << ", Price per kg: $" << strategy->calculatePrice(1) << std::endl;
            }
        }
    }

    bool productExists(const std::string& name) {
        return products.find(name) != products.end();
    }

    void saveProducts() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file for saving products." << std::endl;
            return;
        }

        for (const auto& product : products) {
            WeightBasedPricing* strategy = dynamic_cast<WeightBasedPricing*>(product.second);
            if (strategy) {
                file << product.first << " " << strategy->calculatePrice(1) << std::endl; // saving price per kg
            }
        }

        file.close();
    }

    void loadProducts() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file for loading products." << std::endl;
            return;
        }

        std::string name;
        double pricePerKg;
        while (file >> name >> pricePerKg) {
            addProduct(name, pricePerKg);
        }

        file.close();
    }
};
