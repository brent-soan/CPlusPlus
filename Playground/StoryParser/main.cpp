#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>

int main() {
    std::vector<std::tuple<int, std::string, std::string>> assets;
    std::ifstream storyFile("WITC In-game Story.txt");
    std::string line;
    int checkpoint = 0;
    std::string texture;
    std::string dialogue;

    if (!storyFile.is_open()) {
        std::cerr << "Error opening story file!" << std::endl;
        return 1;
    }

    while (std::getline(storyFile, line)) {
        // Check for Week to update checkpoint
        if (line.find("Week ") != std::string::npos) {
            std::stringstream ss(line);
            std::string temp;
            int weekNum;
            ss >> temp >> weekNum;
            checkpoint = weekNum;
        }
        // Check for texture and dialogue
        else if (line.find("Slides (in order):") == std::string::npos && line.find(":") != std::string::npos && line.length() > 2) {
            size_t colonPos = line.find(":");
            texture = line.substr(0, colonPos);
            dialogue = line.substr(colonPos + 1);

            // Process texture
            if (texture.find("Black Screen") != std::string::npos) {
                texture = ""; // Ignore Black Screen
            } else if (texture.find("Hello World") != std::string::npos) {
                texture = "Hello World.png";
            } else if (texture.length() > 1) {
                texture = texture + ".png";
            }

            // Trim leading/trailing whitespace from dialogue
            size_t start = dialogue.find_first_not_of(" \t\n\r");
            size_t end = dialogue.find_last_not_of(" \t\n\r");
            dialogue = (start == std::string::npos) ? "" : dialogue.substr(start, end - start + 1);

            // Add to assets if texture or dialogue is not empty
            if (!texture.empty() || !dialogue.empty()) {
                assets.emplace_back(checkpoint, texture, dialogue);
            }
        }
    }

    storyFile.close();

    // Print assets to verify
    for (const auto& asset : assets) {
        std::cout << "Checkpoint: " << std::get<0>(asset)
                  << ", Texture: " << std::get<1>(asset)
                  << ", Dialogue: " << std::get<2>(asset) << std::endl;
    }

    return 0;
}
