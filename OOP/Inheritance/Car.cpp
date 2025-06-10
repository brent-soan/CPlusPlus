#include <iostream>
#include <string>
#include "Vehicle.cpp"

class Car : public Vehicle {
public:
    Car(std::string hornSound) {
        this->hornSound = hornSound;
    }
};
