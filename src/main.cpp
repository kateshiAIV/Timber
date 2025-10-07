#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "cloud.h"
#include "bee.h"
#include "branch.h"
#include "enums.h"

using namespace sf;



void updateBranches(int seed, std::vector<Branch>& BranchesArray);







int main()
{


    //Sounds

    SoundBuffer soundBufferChop;
    soundBufferChop.loadFromFile("sound/chop.wav");
    Sound soundChop(soundBufferChop);

    SoundBuffer soundBufferDeath;
    soundBufferDeath.loadFromFile("sound/death.wav");
    Sound soundDeath(soundBufferDeath);

    SoundBuffer soundBufferTime;
    soundBufferTime.loadFromFile("sound/out_of_time.wav");
    Sound soundTime(soundBufferTime);
    

    sf::Font font;
    font.openFromFile("fonts/KOMIKAP.ttf");

    //Game Pause
    sf::Text txtPaused(font, "", 30);
    txtPaused.setString("Press SPACE to start!!!");
    txtPaused.setCharacterSize(75);
    txtPaused.setFillColor(Color::White);
    txtPaused.setFont(font);
    bool paused = true;



    //Game Score
    sf::Text txtScore(font, "", 30);
    txtScore.setString("Score = 0");
    txtScore.setCharacterSize(100);
    txtScore.setFillColor(Color::White);
    txtScore.setFont(font);
    int score = 0;



    FloatRect textRect = txtPaused.getGlobalBounds();
    txtPaused.setOrigin(textRect.getCenter());
    txtPaused.setPosition(sf::Vector2<float>(1920.0f / 2.0f, 1080.0f / 2.0f));
    txtScore.setPosition(sf::Vector2<float>(20, 20));






	//Window;
    VideoMode vm({ 1920u, 1080u });
    RenderWindow window = RenderWindow(vm, "Timberman");


	//Background
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground(textureBackground);
    spriteBackground.setPosition(sf::Vector2<float>(0.0f,0.0f));

    //Tree 
    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree(textureTree);
    spriteTree.setPosition(sf::Vector2<float>(810.0f, 0.0f));


    //Branches
	Branch::LoadTexture();
    std::vector<Branch> BranchesArray =
    {
        Branch(-2000.0f, -2000.0f),
        Branch(-2000.0f, -2000.0f),
        Branch(-2000.0f, -2000.0f),
        Branch(-2000.0f, -2000.0f),
        Branch(-2000.0f, -2000.0f),
        Branch(-2000.0f, -2000.0f)
    };

    //Bees
    Bee::LoadTexture();
    std::vector<Bee> BeesArray =
    {
        Bee(0.0f, 800.0f),
        Bee(0.0f, 700.0f)
    };


    //Clouds
    Cloud::LoadTexture();
    std::vector<Cloud> CloudsArray = {
        Cloud(0.0f, 150.0f),
        Cloud(1500.0f, 0.0f),
        Cloud(1800.0f, 300.0f)
    };







    //Clock
    Clock clock;


    RectangleShape timeBar;
    float timeBarWidth = 960.0f;
    float timeBarHeight = 25.0f;
    timeBar.setSize(sf::Vector2<float>(timeBarWidth, timeBarHeight));
    timeBar.setFillColor(sf::Color::Red);
    timeBar.setPosition(sf::Vector2<float>(((1920.0f / 2) - timeBarWidth/2), 925.0f));

    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarWidth / timeRemaining;


    //Player Setup

    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/player.png");
    Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(sf::Vector2(580.0f, 720.0f));
    side sidePlayer = side::LEFT;

    // Gravestone setup

    Texture textureRIP;
    textureRIP.loadFromFile("graphics/rip.png");
    Sprite spriteRIP(textureRIP);
    spriteRIP.setPosition(sf::Vector2(600.0f, 860.0f));

    // Axe setip

    Texture textureAXE;
    textureAXE.loadFromFile("graphics/axe.png");
    Sprite spriteAXE(textureAXE);
    spriteAXE.setPosition(sf::Vector2(700.0f,830.0f));

    //AXE
    const float AXE_POSITION_RIGHT = 1075.0f;
    const float AXE_POSITION_LEFT = 700.0f;

    //setup flying LOG

    Texture textureLog;
    textureLog.loadFromFile("graphics/log.png");
    Sprite spriteLog(textureLog);
    spriteLog.setPosition(sf::Vector2(810.0f, 720.0f));

    //LOG
    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;
    
    //input
    bool bActiveInput = false;


	//Game loop
    while (window.isOpen()) {
        Time deltaTime = clock.restart();


        if (!paused) {


            // Subtract from the amount of time remaining
            timeRemaining -= deltaTime.asSeconds();
            // size up the time bar
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));


            if (timeRemaining <= 0) {
                paused = true;
                txtPaused.setString("Out of time");
                soundTime.play();
            }

            //Reposition the text based on its new size
            FloatRect textRect = txtPaused.getLocalBounds();
            txtPaused.setOrigin(textRect.getCenter());
            txtPaused.setPosition(sf::Vector2<float>(1920.0f / 2.0f, 1080.0f / 2.0f));
            txtScore.setPosition(sf::Vector2<float>(20, 20));


            //Setup the bees
            for (int i = 0; i < BeesArray.size(); i++)
            {
                if (!BeesArray[i].GetActive())
                {
                    srand((int)rand() % 400);
                    BeesArray[i].SetSpeed((rand() % 200) + 200);
                    srand((int)rand() * 10);
                    float height = (rand() % 500) + 500;
                    BeesArray[i].SetBeePosition(sf::Vector2<float>(2000.0f + (rand()%300), height));
                    BeesArray[i].SetActive(true);
                }
                else
                {
                    BeesArray[i].SetBeePosition
                    (
                        sf::Vector2<float>
                        (
                            BeesArray[i].GetBeePosition().x - (BeesArray[i].GetSpeed() * deltaTime.asSeconds()),
                            BeesArray[i].GetBeePosition().y
                        )
                    );
                    if (BeesArray[i].GetBeePosition().x < -100) 
                    {
                        BeesArray[i].SetActive(false);
                    }
                }
            }

			//Setup the clouds
            for (int i = 0; i < CloudsArray.size(); i++) {
                if (!CloudsArray[i].GetActive()) {
                    srand((int)rand()%300);
                    CloudsArray[i].SetSpeed((rand() % 300)+150);
                    srand((int)rand()%200);
                    float height = (rand() % 150);
                    float length = -(rand() % 700);
                    CloudsArray[i].SetCloudPosition
                    (
                        sf::Vector2<float>
                        (
                            length-150.0f,
                            CloudsArray[i].GetCloudPosition().y
                        )
                    );
                    CloudsArray[i].SetActive(true);
                }
                else {


                    CloudsArray[i].SetCloudPosition
                    (
                        sf::Vector2<float>
                        (
                            CloudsArray[i].GetCloudPosition().x + CloudsArray[i].GetSpeed() * deltaTime.asSeconds(),
                            CloudsArray[i].GetCloudPosition().y
                        )
                    );
                    if (CloudsArray[i].GetCloudPosition().x > 1920.0f)
                    {
                        CloudsArray[i].SetActive(false);
                    }
                }
            }



            // Update the score text
            std::stringstream ss;
            ss << "Score = " << score;
            txtScore.setString(ss.str());




			//Update the branches
            for(int i=0; i<BranchesArray.size();i++ )
            {
				float height = 150.0f * i;
                if (BranchesArray[i].GetBranchSide() == side::LEFT)
                {
                    BranchesArray[i].GetSprite().setPosition(sf::Vector2<float>(610.0f, height));
                    BranchesArray[i].GetSprite().setRotation(sf::degrees(180.0f));
                }
                else if (BranchesArray[i].GetBranchSide() == side::RIGHT)
                {
                    BranchesArray[i].GetSprite().setPosition(sf::Vector2<float>(1330.0f, height));
					BranchesArray[i].GetSprite().setRotation(sf::degrees(0.0f));
                }
                else
                {
					BranchesArray[i].GetSprite().setPosition(sf::Vector2<float>(3000.0f, height));
                }
            
            }

           

            if (logActive)
            {
                spriteLog.setPosition(
                    sf::Vector2(
                        spriteLog.getPosition().x +
                        (logSpeedX * deltaTime.asSeconds()),

                        spriteLog.getPosition().y +
                        (logSpeedY * deltaTime.asSeconds())
                    )
                );

                if (spriteLog.getPosition().x < -100.0f ||
                    spriteLog.getPosition().x > 2000.0f)
                {
                    logActive = false;
                    spriteLog.setPosition(sf::Vector2(810.0f, 780.0f));

                }
            }

            if (BranchesArray[5].GetBranchSide() == sidePlayer) {
                paused = true;
                bActiveInput = false;
                spriteRIP.setPosition(sf::Vector2(525.0f, 760.0f));
                spritePlayer.setPosition(sf::Vector2(2000.0f, 620.0f));
                txtPaused.setString("SQUISHED");

                FloatRect textRect = txtPaused.getLocalBounds();
                txtPaused.setOrigin(textRect.getCenter());

                txtPaused.setPosition(sf::Vector2(1920.0f / 2, 1080.0f / 2));
                soundDeath.play();
            }

        }

        //Event event();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::KeyPressed>() && !paused)
            {
                bActiveInput = true;
                spriteAXE.setPosition(sf::Vector2(2000.0f,
                    spriteAXE.getPosition().y));
            }

        }

        //Exit on ESC
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        //Start on SPACE
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            paused = false;
            timeRemaining = 6;
            score = 0;

            for (int i = 0; i < BranchesArray.size(); i++) 
            {
				BranchesArray[i].SetBranchSide(side::NONE);
            }

            spriteRIP.setPosition(sf::Vector2(675.0f, 2000.0f));
            spritePlayer.setPosition(sf::Vector2(580.0f, 720.0f));
            bActiveInput = true;

        }
        if (bActiveInput)
        {

            if (Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                sidePlayer = side::RIGHT;
                score++;
                timeRemaining += (2 / score) + 0.15;
                spriteAXE.setPosition(sf::Vector2(AXE_POSITION_RIGHT, spriteAXE.getPosition().y));
                spritePlayer.setPosition(sf::Vector2(1200.0f, 720.0f));
                updateBranches(score, BranchesArray);
                spriteLog.setPosition(sf::Vector2(810.0f, 780.0f));
                logSpeedX = -5000.0f;
                logActive = true;
                bActiveInput = false;
                soundChop.play();
            }

            if (Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                sidePlayer = side::LEFT;
                score++;
                timeRemaining += (2 / score) + 0.15;
                spriteAXE.setPosition(sf::Vector2(AXE_POSITION_LEFT, spriteAXE.getPosition().y));
                spritePlayer.setPosition(sf::Vector2(580.0f, 720.0f));
                updateBranches(score, BranchesArray);
                spriteLog.setPosition(sf::Vector2(810.0f, 720.0f));
                logSpeedX = 5000.0f;
                logActive = true;
                bActiveInput = false;
                soundChop.play();
            }


        }



        window.clear();                       
        window.draw(spriteBackground);    

        for (int i = 0; i < CloudsArray.size(); i++) {
            window.draw(CloudsArray[i].GetSprite());
        }
        for (int i = 0; i < BeesArray.size(); i++) {
            window.draw(BeesArray[i].GetSprite());
        }
        window.draw(spriteTree);
        window.draw(txtScore);
        window.draw(timeBar);
        window.draw(spriteLog);
        window.draw(spritePlayer);
        window.draw(spriteAXE);
        window.draw(spriteRIP);


        for (int i = 0; i < BranchesArray.size(); i++) {
            window.draw(BranchesArray[i].GetSprite());
        }


        if (paused)
        {
            window.draw(txtPaused);
        }

        window.display();                     
    }

    
    return 0;
}


void updateBranches(int seed, std::vector<Branch>& BranchesArray)
{
    for (int j = BranchesArray.size() - 1; j > 0; j--) {
		BranchesArray[j].SetBranchSide(BranchesArray[j - 1].GetBranchSide());
    }
    // Spawn a new branch at position 0
 // LEFT, RIGHT or NONE
    srand((int)time(0) + seed);
    int r = (rand() % 5);
    switch (r) {
    case 0:
		BranchesArray[0].SetBranchSide(side::LEFT);
        break;
    case 1:
        BranchesArray[0].SetBranchSide(side::RIGHT);
        break;
    default:
        BranchesArray[0].SetBranchSide(side::NONE);
        break;

    }
}
