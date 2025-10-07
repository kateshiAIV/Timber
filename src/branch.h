#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Audio.hpp>
#include "enums.h"

class Branch 
{
private:

	static sf::Texture textureBranch;
	sf::Sprite spriteBranch;
	side position;

public:

	Branch(float x, float y);
	static void LoadTexture();
	side GetBranchSide() const;
	void SetBranchSide(side val);
	sf::Sprite& GetSprite(); // to draw it later
	sf::Vector2<float> GetBranchPosition() const;
	void SetBranchPosition(const sf::Vector2<float>& pos);
};
