#include <iostream>
#include <string>
#include "Dog.cpp"

int main() {
	Dog dog1("Princess", "Pit bull");

	std::cout << dog1.getName() << " the " << dog1.getBreed();

	return 0;
}
