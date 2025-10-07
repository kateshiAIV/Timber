#include "player.h"

Player::Player(float x, float y) : spritePlayer(texturePlayer), sidePlayer(side::LEFT)
{
    spritePlayer.setPosition(sf::Vector2<float>(x, y));
}


side Player::GetSidePlayer() const
{
    return sidePlayer;
}

void Player::SetSidePlayer(side val)
{
    this->sidePlayer = val;
}


sf::Vector2<float> Player::GetPlayerPosition() const
{
    return spritePlayer.getPosition();
}

void Player::SetPlayerPosition(const sf::Vector2<float>& pos)
{
    spritePlayer.setPosition(pos);
}

sf::Sprite& Player::GetSprite() {
    return spritePlayer;
}


sf::Texture Player::texturePlayer;

void Player::LoadTexture() {
    if (!texturePlayer.loadFromFile("graphics/player.png")) {
        std::cerr << "Failed to load player texture!\n";
    }
}