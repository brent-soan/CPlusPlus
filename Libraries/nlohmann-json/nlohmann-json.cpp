#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

int main() {
    auto var1 = json::parse("{\"var\": \"string\"}");
    std::cout << var1 << "\n";

    var1["var"] = "new string";
    std::cout << var1 << "\n";
    std::cout << var1["var"] << "\n";


}