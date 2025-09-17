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

	//Game loop
    while (window.isOpen()) {


        //Exit on ESC
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        window.clear();                       
        window.draw(spriteBackground);        
        window.display();                     
    }

    
    return 0;
}
