#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


using namespace sf;




int main()
{
    VideoMode vm({ 1920u, 1080u });
    RenderWindow window = RenderWindow(vm, "Timberman");
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground(textureBackground);
    spriteBackground.setPosition(sf::Vector2<float>(0.0f,0.0f));


    std::ofstream("file.txt") << "file content";

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        window.clear();                       // очистка окна
        window.draw(spriteBackground);        // рисуем фон
        window.display();                     // выводим на экран
    }

    
    return 0;
}
