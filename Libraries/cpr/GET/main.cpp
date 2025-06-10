#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url{ "https://httpbin.io/get" });
    std::cout << r.url << "\n";
    std::cout << r.status_code << "\n";
    std::cout << r.header["content-type"] << "\n";
    std::cout << r.text;
}