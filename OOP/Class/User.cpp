#include <iostream>
#include <string>

class User {
  public: // Set to private preferably (Encapsulatio>
    std::string name;
    int age;

    User(std::string name, int age) {
      this->name = name;
      this->age = age;
    }

    void greet() {
      std::cout << "Hello " << this->name << "!";
    }
};
