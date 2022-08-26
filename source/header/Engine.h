#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Engine
{
private:
    /* vars */
    sf::RenderWindow *window;
    sf::Event event;
    /* functions */
    void initVariables();
    void initWindow();
    void pollEvents();

public:
    /* constructors */
    Engine();
    ~Engine();

    /* functions */
    void update();
    void render();

    /* accessors */
    const bool running() const;
};
