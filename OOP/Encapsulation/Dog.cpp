#include <iostream>
#include <string>

class Dog {
  std::string name; // Private
  std::string breed; // Private

  public:
    Dog(std::string name, std::string breed) {
      this->name = name;
      this->breed = breed;
    }

    void bark() {
      std::cout << "Woof!";
    }

    std::string getName() {
      return this->name;
    }

    void setName(std::string name) {
      this->name = name;
    }

    std::string getBreed() {
      return this->breed;
    }

    void setBreed(std::string breed) {
      this->breed = breed;
    }
};
