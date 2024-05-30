#include <iostream>
#include <vector>
#include "Product.h"
#include "WeightBasedPricing.h"
#include "IoCContainer.h"
#include "ProductFactory.h"
#include "ProductCatalog.h"

class Cart {
private:
    std::vector<Product> products;
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void listProducts() const {
        double totalCost = 0;
        for (const auto& product : products) {
            double cost = product.getPrice();
            totalCost += cost;
            std::cout << "Product: " << product.getName() << ", Weight: " << product.getWeight() 
                      << "kg, Price: $" << cost << std::endl;
        }
        std::cout << "Total cost: $" << totalCost << std::endl;
    }
};

int main() {
    IoCContainer container;
    ProductCatalog catalog(container);
    Cart cart;
    
    std::string mode;
    while (true) {
        std::cout << "Enter mode (admin/customer) or 'exit' to quit: ";
        std::cin >> mode;

        if (mode == "exit") break;

        if (mode == "admin") {
            std::string password;
            std::cout << "Enter admin password: ";
            std::cin >> password;

            if (password != "1111") {
                std::cerr << "Invalid password. Exiting admin mode." << std::endl;
                continue;
            }

            std::string productName;
            double productPrice;
            while (true) {
                std::cout << "Enter new product name (or 'back' to finish): ";
                std::cin >> productName;
                if (productName == "back") break;

                std::cout << "Enter product price per kg: ";
                std::cin >> productPrice;

                catalog.addProduct(productName, productPrice);
                std::cout << "Product added successfully." << std::endl;
            }
        } else if (mode == "customer") {
            ProductFactory productFactory(container);
            std::string productName;
            double productWeight;

            catalog.listProducts();

            while (true) {
                std::cout << "Enter product name (or 'count' to calculate total, 'exit' to quit): ";
                std::cin >> productName;

                if (productName == "count") {
                    cart.listProducts();
                    continue;
                } else if (productName == "exit") {
                    break;
                }

                if (!catalog.productExists(productName)) {
                    std::cerr << "Unknown product type. Please try again." << std::endl;
                    continue;
                }

                std::cout << "Enter product weight: ";
                std::cin >> productWeight;

                Product product = productFactory.createProduct(productName, productWeight);
                cart.addProduct(product);
                std::cout << "Product added to cart." << std::endl;
            }
        } else {
            std::cerr << "Invalid mode. Please try again." << std::endl;
        }
    }

    return 0;
}
