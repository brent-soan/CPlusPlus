#include "StoryModel.h"
#include "Structs.h"
#include <fstream>
#include <vector>
#include "fmt/core.h"

StoryModel::StoryModel() {
	std::ifstream file = std::ifstream("Story.txt");
	std::string line;
    
    int checkpoint = -4;
    bool isMainScene = false;
    bool isLocationScene = false;
	bool isNewspaper = false;

	while(std::getline(file, line)) {
		if(line.starts_with("Week")) {
			line.erase(0, 5); // Remove "Week "
			checkpoint = std::stoi(line);
		}

		if(isMainScene) {
            if(line.size() > 3) {
                MainSceneAsset mainSceneAsset;
                mainSceneAsset.checkpoint = checkpoint;

                if(line.at(0) >= '0' && line.at(0) <= '9') { // backgroundTexture
                    if(line.find("Black Screen") != std::string::npos) {
                        mainSceneAsset.backgroundTexture = "";
                    } else {
                        if(line.at(1) >= '0' && line.at(1) <= '9') {
                            line.erase(0, 4); // Remove "10. "
                        } else {
                            line.erase(0, 3); // Remove "1. "
                        }

                        line.pop_back(); // Remove semicolon
                        line.append(".png");
                        mainSceneAsset.backgroundTexture = fmt::format("Assets/Textures/Scenes/{}", line);
                    }
                } else if(line.starts_with("   ")) { // Dialogue
                    line.erase(0, 3); // Remove "   "

                    if(line.at(1) >= '0' && line.at(1) <= '9') {
                        line.erase(0, 4); // Remove "10. "
                    } else {
                        line.erase(0, 3); // Remove "1. "
                    }

                    mainSceneAsset.dialogue = line;
                }

                mainSceneAssets.push_back(mainSceneAsset);
            }
		} else if(isLocationScene) {
            if(line.size() > 8) {
                LocationSceneAsset locationSceneAsset;


            }
		} else if(isNewspaper) {

		}

		if(line.starts_with("Slides")) {
            isMainScene = true;
			isNewspaper = false;
		} else if(line.starts_with("Location")) {
            isLocationScene = true;
            isMainScene = false;
        } else if(line.starts_with("Newspaper")) {
            isNewspaper = true;
            isLocationScene = false;
        }
	}
}

std::vector<MainSceneAsset> StoryModel::getMainSceneAssets(int checkpoint) {
	
}

std::vector<LocationSceneAsset> StoryModel::getLocationSceneAssets(int checkpoint) {
	
}