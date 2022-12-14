#pragma once
#include <algorithm>
#include <queue>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include "imgui-SFML.h"
#include "../scene/Scene.h"


class Editor
{
private:
    /* vars */
    sf::RenderWindow *window;
    sf::Event event;
    Scene scene;
    int selectedNodeId = 1;
    std::shared_ptr<Node> selectedNode;
    /* init functions */
    void initVariables();
    void initWindow();

    /* update functions */
    void pollEvents();
    void updateScene();
    
    /* render functions */
    void renderGUI();
    void renderSceneTreeNode(std::shared_ptr<Node> node);
    void renderDetails();
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
