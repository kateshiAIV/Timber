#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Audio.hpp>

class Bee 
{
private:
    static sf::Texture textureBee;
    sf::Sprite spriteBee;
    bool beeActive;
    float beeSpeed;

public:
    Bee(float x, float y);

    static void LoadTexture();

    bool GetActive() const;
    void SetActive(bool val);

    float GetSpeed() const;
    void SetSpeed(float val);

    sf::Vector2<float> GetBeePosition() const;
    void SetBeePosition(const sf::Vector2<float>& pos);

    sf::Sprite& GetSprite(); // to draw it later


};