#include "cloud.h"

Cloud::Cloud(float x, float y)
    : cloudActive(true), cloudSpeed(150.0f), spriteCloud(textureCloud)
{
    spriteCloud.setPosition(sf::Vector2f(x, y));
}

bool Cloud::GetActive() const {
    return cloudActive;
}

void Cloud::SetActive(bool val) {
    cloudActive = val;
}

float Cloud::GetSpeed() const {
    return cloudSpeed;
}

void Cloud::SetSpeed(float val) {
    cloudSpeed = val;
}

sf::Vector2<float> Cloud::GetCloudPosition() const {
    return spriteCloud.getPosition();
}

void Cloud::SetCloudPosition(const sf::Vector2<float>& pos) {
    spriteCloud.setPosition(pos);
}

sf::Sprite& Cloud::GetSprite() {
    return spriteCloud;
}

sf::Texture Cloud::textureCloud;

void Cloud::LoadTexture() {
    if (!textureCloud.loadFromFile("graphics/cloud.png")) {
        std::cerr << "Failed to load cloud texture!\n";
    }
}
