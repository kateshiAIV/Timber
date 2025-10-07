#include "branch.h"

Branch::Branch(float x, float y) : position(side::NONE), spriteBranch(textureBranch)
{
	spriteBranch.setPosition(sf::Vector2<float>(x, y));
	spriteBranch.setOrigin(sf::Vector2<float>(220.0f, 20.0f));
}


side Branch::GetPosition() const 
{
	return position;
}


void Branch::SetPosition(side val)
{
	this->position = val;
}

sf::Sprite& Branch::GetSprite()
{
	return spriteBranch;
}

sf::Texture Branch::textureBranch;

void Branch::LoadTexture() 
{
	if (!textureBranch.loadFromFile("graphics/branch.png")) 
	{
		std::cerr << "Failed to load branch texture!\n";
	}
}