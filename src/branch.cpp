#include "branch.h"

Branch::Branch(float x, float y) : position(side::RIGHT), spriteBranch(textureBranch)
{
	spriteBranch.setPosition(sf::Vector2<float>(x, y));
	spriteBranch.setOrigin(sf::Vector2<float>(220.0f, 20.0f));
}


side Branch::GetBranchSide() const
{
	return position;
}


void Branch::SetBranchSide(side val)
{
	this->position = val;
}

sf::Sprite& Branch::GetSprite()
{
	return spriteBranch;
}

sf::Vector2<float> Branch::GetBranchPosition() const {
	return spriteBranch.getPosition();
}

void Branch::SetBranchPosition(const sf::Vector2<float>& pos) {
	spriteBranch.setPosition(pos);
}

sf::Texture Branch::textureBranch;

void Branch::LoadTexture() 
{
	if (!textureBranch.loadFromFile("graphics/branch.png")) 
	{
		std::cerr << "Failed to load branch texture!\n";
	}
}