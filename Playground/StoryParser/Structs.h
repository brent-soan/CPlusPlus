#pragma once

#include <string>

struct MainSceneAsset {
    int checkpoint;
    std::string backgroundTexture;
    std::string dialogue;
};

struct LocationSceneAsset {
    int checkpoint;
    std::string backgroundTexture;
    std::string foregroundTexture;
    std::string dialogue;
};

struct NewspaperAsset {
    int checkpoint;
    std::string headline;
};