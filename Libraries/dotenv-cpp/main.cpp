#define _CRT_SECURE_NO_WARNINGS // Disable warnings for unsafe functions in Visual Studio

#include <iostream>  
#include <string>  
#include <dotenv.h>

int main()  
{  
    dotenv::init(".env");  
    std::cout << std::getenv("KEY") << std::endl; // Unsafe in Visual Studio
    return 0;  
}