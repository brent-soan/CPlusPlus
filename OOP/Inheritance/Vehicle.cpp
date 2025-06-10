#include <iostream>
#include <string>

class Vehicle {
protected: // Enables the Car class to access this attribute
    std::string hornSound;

public:
    void honk() {
        std::cout << this->hornSound;
    }
};
