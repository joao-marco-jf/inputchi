// src/gui.cpp
#include "inputchi/gui.h"
#include <iostream>

InputchiGUI::InputchiGUI() : isInitialized(false) {}

bool InputchiGUI::initialize()
{
    // Create the window
    window.create(sf::VideoMode(400, 500), "Inputchi", sf::Style::Close);
    window.setFramerateLimit(30);

    // Load font
    if (!font.loadFromFile("assets/arial.ttf"))
    {
        std::cerr << "Erro ao carregar fonte" << std::endl;
        return false;
    }

    // Load character textures
    if (!happyTexture.loadFromFile("assets/happy.png"))
    {
        std::cerr << "Erro ao carregar textura happy.png" << std::endl;
        return false;
    }

    if (!sadTexture.loadFromFile("assets/sad.png"))
    {
        std::cerr << "Erro ao carregar textura sad.png" << std::endl;
        return false;
    }

    // Setup character sprite
    characterSprite.setTexture(happyTexture);
    characterSprite.setPosition(100, 150);
    characterSprite.setScale(0.8f, 0.8f);

    // Setup status texts
    foodText.setFont(font);
    foodText.setPosition(20, 20);
    foodText.setCharacterSize(18);

    timeText.setFont(font);
    timeText.setPosition(20, 60);
    timeText.setCharacterSize(18);

    statusText.setFont(font);
    statusText.setPosition(100, 400);
    statusText.setCharacterSize(24);

    // Setup progress bars
    // Food bar
    foodBarBg.setSize(sf::Vector2f(300, 20));
    foodBarBg.setFillColor(sf::Color(100, 100, 100));
    foodBarBg.setPosition(80, 25);

    foodBar.setSize(sf::Vector2f(0, 20));
    foodBar.setFillColor(sf::Color(0, 255, 0));
    foodBar.setPosition(80, 25);

    // Time bar
    timeBarBg.setSize(sf::Vector2f(300, 20));
    timeBarBg.setFillColor(sf::Color(100, 100, 100));
    timeBarBg.setPosition(80, 65);

    timeBar.setSize(sf::Vector2f(0, 20));
    timeBar.setFillColor(sf::Color(255, 165, 0));
    timeBar.setPosition(80, 65);

    isInitialized = true;
    return true;
}

void InputchiGUI::update(int food, int timeLeft, bool hangry)
{
    if (!isInitialized)
        return;

    // Update text
    foodText.setString("Comida:");
    timeText.setString("Tempo:");

    if (hangry)
    {
        characterSprite.setTexture(sadTexture);
        statusText.setString("Estou com fome!");
        statusText.setFillColor(sf::Color::Red);
    }
    else
    {
        characterSprite.setTexture(happyTexture);
        statusText.setString("Estou feliz!");
        statusText.setFillColor(sf::Color::Green);
    }

    // Update progress bars
    // Cap food at 10 for display purposes
    float foodRatio = std::min(food, 10) / 10.0f;
    foodBar.setSize(sf::Vector2f(300 * foodRatio, 20));

    float timeRatio = timeLeft / 60.0f;
    timeBar.setSize(sf::Vector2f(300 * timeRatio, 20));
}

bool InputchiGUI::isOpen() const
{
    return window.isOpen();
}

void InputchiGUI::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void InputchiGUI::render()
{
    if (!isInitialized)
        return;

    window.clear(sf::Color(240, 240, 240));

    // Draw progress bars backgrounds
    window.draw(foodBarBg);
    window.draw(timeBarBg);

    // Draw progress bars
    window.draw(foodBar);
    window.draw(timeBar);

    // Draw texts
    window.draw(foodText);
    window.draw(timeText);

    // Draw character
    window.draw(characterSprite);

    // Draw status
    window.draw(statusText);

    window.display();
}