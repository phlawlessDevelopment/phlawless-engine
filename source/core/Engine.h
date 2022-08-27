#pragma once

#include <SFML/Graphics.hpp>

struct Inputs{
    bool up;
    bool down;
    bool left;
    bool right;
};
class Engine
{
private:
    /* vars */
    sf::RenderWindow *window;
    sf::Event event;
    Inputs inputs;
    /* init functions */
    void initVariables();
    void initWindow();

    /* update functions */
    void pollEvents();
    void updateEntities();

public:
    /* constructors */
    Engine();
    ~Engine();

    /* functions */
    void update(float delta);
    void render();

    /* accessors */
    const bool running() const;
};
