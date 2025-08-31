#define _CRT_SECURE_NO_WARNINGS // Disable warnings for unsafe functions in Visual Studio

#include <iostream>  
#include <string>  
#include <dotenv.h>

int main() {  
    dotenv::init(".env");  
	const char* key = std::getenv("KEY"); // getenv() returns a pointer to the string or nullptr if not found

	try {
		if(key) {
			std::cout << "KEY = " << key << std::endl;
		}
		else {
			throw std::runtime_error("KEY was not found");
		}
	}
	catch(const std::runtime_error& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}