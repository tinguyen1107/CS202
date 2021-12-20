#include "../Header/CSound.h"

#include <iostream>

CSound* CSound::instance = nullptr;

CSound* CSound::getInstance() {
    if (!instance) instance = new CSound;
    return instance;
}

CSound::~CSound() {
    delete instance; 
}

CSound::CSound() {
    std::string path = "Resource/Sound/";

    
    buffer.loadFromFile(path + "0.wav");

    this->success.setBuffer(buffer);
    this->success.setVolume(40);
    this->success.play(); 
}
