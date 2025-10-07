#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Audio.hpp>
#include "enums.h"


class Player {
private:
    static sf::Texture texturePlayer;
    sf::Sprite spritePlayer;
    side sidePlayer;

public:
    Player(float x, float y);

    static void LoadTexture();

    side GetSidePlayer() const;
    void SetSidePlayer(side val);

    sf::Vector2<float> GetPlayerPosition() const;
    void SetPlayerPosition(const sf::Vector2<float>& pos);

    sf::Sprite& GetSprite(); // to draw it later
};

