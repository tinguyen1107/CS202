#include "../Header/CSound.h"

#include <iostream>

CSoundEffect::CSoundEffect(string path, int volume) {
    soundBuffer = new sf::SoundBuffer;
    if (!soundBuffer->loadFromFile(path)) {
        cout << "LOAD SOUND FAILED FROM: " << path << endl;
        throw - 1; // -1 mean can't load
    }
    sound = new sf::Sound(*soundBuffer);
    sound->setVolume((float)volume);
}

CSoundEffect::~CSoundEffect() {
    delete soundBuffer;
    delete sound;
}

void CSoundEffect::playSound() { this->sound->play(); }

CSound* CSound::instance = nullptr;

CSound* CSound::getInstance() {
    if (!instance) instance = new CSound;
    return instance;
}

CSound::~CSound() {
    delete instance;

    delete label;
    delete localFont;

    delete intro;
    delete car_collision;
    delete truck_collision;
    delete bird_collision;
    delete dinausor_collision;
    delete people_move;
    delete playing;
    delete waiting;
}

void CSound::setStateLabel(bool _isPlaying) {
    this->isPlaying = _isPlaying;
    if (this->isPlaying)
        this->label->setPosition(sf::Vector2f(40.0f, 460.0f));
    else
        this->label->setPosition(sf::Vector2f(80.0f, 80.0f));
}

void CSound::toggleActive(bool _update) {
    if (!_update) this->isActive = !this->isActive;

    sf::Color color = this->isActive ? sf::Color::Green : sf::Color::Red;
    this->label->setColor(color);
}

void CSound::drawLabelTo(sf::RenderWindow& window) {
    this->label->drawTo(window);
}

string CSound::getStateButton() {
    return isActive ? "Turn off sound." : "Turn on sound.";
}

void CSound::play(Sounds _sound) {
    if (!this->isActive) return;
   
    switch (_sound) {
    case Sounds::intro:
        this->intro->playSound();
        break;
    case Sounds::car_collision:
        this->car_collision->playSound();
        break;
    case Sounds::truck_collision:
        this->truck_collision->playSound();
        break;
    case Sounds::bird_collision:
        this->bird_collision->playSound();
        break;
    case Sounds::dinosaur_collision:
        this->dinausor_collision->playSound();
        break;
    case Sounds::people_move:
        this->people_move->playSound();
        break;
    case Sounds::playing:
        this->playing->playSound();
        break;
    case Sounds::waiting:
        this->waiting->playSound();
        break;
    }
}

CSound::CSound() {
    this->label = new CCirclesAndText(sf::Vector2f(0, 0), localFont->getInstance()->ArialRounded, "Sound");
    this->isPlaying = false;
    this->isActive = true;

    // Load sounds
    std::string path = "Resource/Sound/";
    try {
        intro = new CSoundEffect(path + "intro.wav");
        car_collision = new CSoundEffect(path + "car-collision.wav");
        truck_collision = new CSoundEffect(path + "truck-collision.wav");
        bird_collision = new CSoundEffect(path + "bird-collision.wav");
        dinausor_collision = new CSoundEffect(path + "dinausor-collision.wav");
        people_move = new CSoundEffect(path + "people-move.wav", 30);
        playing = new CSoundEffect(path + "playing.wav");
        waiting = new CSoundEffect(path + "waiting.wav");
    } catch (int x) {
        if (x == -1) {
            cout << "LOAD SOUND FAILED" << endl;
            this->isActive = false;
        }
    }

    toggleActive(true);
    cout << "LOAD SOUND SUCCESS" << endl;
}