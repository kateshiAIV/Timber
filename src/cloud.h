#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Audio.hpp>

class Cloud {
private:
    static sf::Texture textureCloud;
    sf::Sprite spriteCloud;
    bool cloudActive;
    float cloudSpeed;

public:
    Cloud(float x, float y);

    static void LoadTexture();

    bool GetActive() const;
    void SetActive(bool val);

    float GetSpeed() const;
    void SetSpeed(float val);

    sf::Vector2<float> GetCloudPosition() const;
    void SetCloudPosition(const sf::Vector2<float>& pos);

    sf::Sprite& GetSprite(); // to draw it later







};
