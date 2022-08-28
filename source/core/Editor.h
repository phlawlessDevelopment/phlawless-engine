#pragma once
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include "imgui-SFML.h"
#include "../scene/Scene.h"

struct Inputs{
    bool up;
    bool down;
    bool left;
    bool right;
};

class Editor
{
private:
    /* vars */
    sf::RenderWindow *window;
    sf::Event event;
    Inputs inputs;
    // Scene scene;
    /* init functions */
    void initVariables();
    void initWindow();

    /* update functions */
    void pollEvents();
    void updateScene();

public:
    /* constructors */
    Editor();
    ~Editor();

    /* functions */
    void update(sf::Clock deltaClock);
    void render();

    /* accessors */
    const bool running() const;
};
