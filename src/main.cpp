#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


using namespace sf;




int main()
{

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


	//Game loop
    while (window.isOpen()) {


        //Exit on ESC
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        window.clear();                       
        window.draw(spriteBackground);    
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.display();                     
    }

    
    return 0;
}
