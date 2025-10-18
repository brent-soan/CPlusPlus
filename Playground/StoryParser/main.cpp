#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

int main() {
    std::vector<std::tuple<int, std::string, std::string>> assets;
    std::ifstream file = std::ifstream("WITC In-game Story.txt");
    std::string line;
    int checkpoint = -1;
    std::string texture = "EMPTY";
    std::string dialogue = "EMPTY";
    

    while(std::getline(file, line)) {
        std::tuple<int, std::string, std::string> asset;

        if(line.size() < 2) { // Empty line
            texture = "EMPTY";
            dialogue = "EMPTY";
        } else if(line.starts_with("Act")) {
            checkpoint = -1;
            texture = "EMPTY";
            dialogue = "EMPTY";
        } else if(line.starts_with("Week")) { // Checkpoint
            line.erase(0, 5); // Remove "Week "
            //std::cout << line << std::endl;
            checkpoint = std::stoi(line);
            texture = "EMPTY";
        } else if(line.size() > 3) {
            if(line.at(0) >= '0' && line.at(0) <= '9') { // Texture
                if(line.at(1) >= '0' && line.at(1) <= '9') {
                    line.erase(0, 4); // Remove "10. "
                } else {
                    line.erase(0, 3); // Remove "1. "
                }

                line.pop_back(); // Remove semicolon
                line.append(".png");
                //std::cout << line << std::endl;
                texture = line;
                dialogue = "EMPTY";
            } else if(line.starts_with("   ")) { // Dialogue
                line.erase(0, 3); // Remove "   "

                if(line.at(1) >= '0' && line.at(1) <= '9') {
                    line.erase(0, 4); // Remove "10. "
                }
                else {
                    line.erase(0, 3); // Remove "1. "
                }

                //std::cout << line << std::endl;
                dialogue = line;
            }
        }

        if(checkpoint != -1 && texture != "EMPTY" && dialogue != "EMPTY") {
            assets.push_back(std::make_tuple(checkpoint, texture, dialogue));
        }
    }

    for(const auto& asset : assets) {
        std::cout << "Checkpoint: " << std::get<0>(asset)
            << ", Texture: " << std::get<1>(asset)
            << ", Dialogue: " << std::get<2>(asset) << std::endl;
    }

    file.close();

    return 0;
}