#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;



int main()
{
    VideoMode vm({ 1920u, 1080u });
    RenderWindow window = RenderWindow(vm, "Timberman");

    while (window.isOpen()) {

        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

    }
    
    return 0;
}
