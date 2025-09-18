#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>


using namespace sf;




int main()
{

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

    //Bee 
    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee(textureBee);
    spriteBee.setPosition(sf::Vector2<float>(0.0f, 800.0f));
    bool beeActive = false;
    float beeSpeed = 0.0f;


    //Clouds
    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");
    Sprite spriteCloud1(textureCloud);
    Sprite spriteCloud2(textureCloud);
    Sprite spriteCloud3(textureCloud);

    spriteCloud1.setPosition(sf::Vector2<float>(0.0f, 0.0f));
    spriteCloud2.setPosition(sf::Vector2<float>(250.0f, 0.0f));
    spriteCloud3.setPosition(sf::Vector2<float>(500.0f, 0.0f));

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;


    //Clock
    Clock clock;


    RectangleShape timeBar;
    float timeBarWidth = 960.0f;
    float timeBarHeight = 40.0f;
    timeBar.setSize(sf::Vector2<float>(timeBarWidth, timeBarHeight));
    timeBar.setFillColor(sf::Color::Red);
    timeBar.setPosition(sf::Vector2<float>(((1920.0f / 2) - timeBarWidth/2), 900.0f));

    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarWidth / timeRemaining;


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
            }

            //Reposition the text based on its new size
            FloatRect textRect = txtPaused.getLocalBounds();
            txtPaused.setOrigin(textRect.getCenter());
            txtPaused.setPosition(sf::Vector2<float>(1920.0f / 2.0f, 1080.0f / 2.0f));
            txtScore.setPosition(sf::Vector2<float>(20, 20));



            //Setup the bee
            if (!beeActive)
            {
                srand((int)time(0));
                beeSpeed = (rand() % 200) + 200;

                srand((int)time(0) * 10);
                float height = (rand() % 500) + 500;
                spriteBee.setPosition(sf::Vector2<float>(2000.0f, height));
                beeActive = true;

            }
            else
            {
                spriteBee.setPosition
                (

                    sf::Vector2<float>(
                        spriteBee.getPosition().x - (beeSpeed * deltaTime.asSeconds()),
                        spriteBee.getPosition().y
                    )
                );
                if (spriteBee.getPosition().x < -100)
                {
                    // Set it up ready to be a whole new bee next frame
                    beeActive = false;
                }
            }



            //setup Cloud1
            if (!cloud1Active) {
                srand((int)time);
                cloud1Speed = (rand() % 300);
                srand((int)time);
                float height = (rand() % 150);
                float length = -(rand() % 700);
                spriteCloud1.setPosition
                (
                    sf::Vector2<float>(
                        length,
                        height
                    )
                );
                cloud1Active = true;

            }
            else
            {
                spriteCloud1.setPosition
                (
                    sf::Vector2<float>
                    (
                        spriteCloud1.getPosition().x +
                        (cloud1Speed * deltaTime.asSeconds()),
                        spriteCloud1.getPosition().y
                    )
                );

                // Has the cloud reached the right hand edge of the screen?
                if (spriteCloud1.getPosition().x > 1920)
                {
                    // Set it up ready to be a whole new cloud next frame
                    cloud1Active = false;
                }


            }


            //setup Cloud2
            if (!cloud2Active) {
                srand((int)time * 20);
                cloud2Speed = (rand() % 300);
                srand((int)time * 20);
                float height = (rand() % 300) - 150;
                float length = -(rand() % 700);
                spriteCloud2.setPosition
                (
                    sf::Vector2<float>(
                        length,
                        height
                    )
                );
                cloud2Active = true;

            }
            else
            {
                spriteCloud2.setPosition
                (
                    sf::Vector2<float>
                    (
                        spriteCloud2.getPosition().x +
                        (cloud2Speed * deltaTime.asSeconds()),
                        spriteCloud2.getPosition().y
                    )
                );

                // Has the cloud reached the right hand edge of the screen?
                if (spriteCloud2.getPosition().x > 1920)
                {
                    // Set it up ready to be a whole new cloud next frame
                    cloud2Active = false;
                }


            }

            //setup Cloud3
            if (!cloud3Active) {
                srand((int)time * 30);
                cloud3Speed = (rand() % 300);
                srand((int)time * 30);
                float height = (rand() % 450) - 150;
                float length = -(rand() % 700);
                spriteCloud3.setPosition
                (
                    sf::Vector2<float>(
                        length,
                        height
                    )
                );
                cloud3Active = true;

            }
            else
            {
                spriteCloud3.setPosition
                (
                    sf::Vector2<float>
                    (
                        spriteCloud3.getPosition().x +
                        (cloud3Speed * deltaTime.asSeconds()),
                        spriteCloud3.getPosition().y
                    )
                );

                // Has the cloud reached the right hand edge of the screen?
                if (spriteCloud3.getPosition().x > 1920)
                {
                    // Set it up ready to be a whole new cloud next frame
                    cloud3Active = false;
                }


            }

            // Update the score text
            std::stringstream ss;
            ss << "Score = " << score;
            txtScore.setString(ss.str());

        }

        //Exit on ESC
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        //Exit on ESC
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            paused = false;
            timeRemaining = 6;
            score = 0;
        }

        window.clear();                       
        window.draw(spriteBackground);    
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.draw(txtScore);
        window.draw(timeBar);

        if (paused)
        {
            window.draw(txtPaused);
        }

        window.display();                     
    }

    
    return 0;
}
