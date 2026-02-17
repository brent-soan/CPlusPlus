#pragma once

#include <vector>
#include "Structs.h"

class StoryModel {
    private:
        std::vector<MainSceneAsset> mainSceneAssets;
        std::vector<LocationSceneAsset> locationSceneAssets;

    public:
        StoryModel();

        std::vector<MainSceneAsset> getMainSceneAssets(int checkpoint);
        std::vector<LocationSceneAsset> getLocationSceneAssets(int checkpoint);
};