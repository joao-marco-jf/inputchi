// include/inputchi/gui.h
#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <string>

class InputchiGUI
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Texture happyTexture;
    sf::Texture sadTexture;
    sf::Sprite characterSprite;

    // Status texts
    sf::Text foodText;
    sf::Text timeText;
    sf::Text statusText;

    // Progress bars
    sf::RectangleShape foodBar;
    sf::RectangleShape foodBarBg;
    sf::RectangleShape timeBar;
    sf::RectangleShape timeBarBg;

    bool isInitialized;

public:
    InputchiGUI();
    bool initialize();
    void update(int food, int timeLeft, bool hangry);
    bool isOpen() const;
    void processEvents();
    void render();
};

#endif // GUI_H