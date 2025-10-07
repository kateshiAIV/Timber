#include "bee.h"

Bee::Bee(float x, float y) : beeActive(true), beeSpeed(250.0f), spriteBee(textureBee)
{
	spriteBee.setPosition(sf::Vector2<float>(x, y));
}

bool Bee::GetActive() const
{
    return beeActive;
}

void Bee::SetActive(bool val)
{
    this->beeActive = val;
}

float Bee::GetSpeed() const
{
    return beeSpeed;
}

void Bee::SetSpeed(float val) 
{
    this->beeSpeed = val;
}


sf::Vector2<float> Bee::GetBeePosition() const
{
    return spriteBee.getPosition();
}

void Bee::SetBeePosition(const sf::Vector2<float>& pos) 
{
    spriteBee.setPosition(pos);
}

sf::Texture Bee::textureBee;

void Bee::LoadTexture() 
{
    if (!textureBee.loadFromFile("graphics/bee.png")) {
        std::cerr << "Failed to load bee texture!\n";
    }
}

sf::Sprite& Bee::GetSprite()
{
    return spriteBee;
}
