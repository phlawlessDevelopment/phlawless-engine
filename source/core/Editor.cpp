#include "Editor.h"

/* private functions */
void Editor::initVariables()
{
    this->window = nullptr;
};
void Editor::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "phlawless-engine");
    ImGui::SFML::Init(*this->window);
};

/* constructors */
Editor::Editor()
{
    this->initVariables();
    this->initWindow();
};

Editor::~Editor()
{
    // delete this->window;
    ImGui::SFML::Shutdown();
};

void Editor::pollEvents()
{   
    while (this->window->pollEvent(this->event) )
    {
        ImGui::SFML::ProcessEvent(*this->window, this->event);
        switch (this->event.type)
        {

        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape)
                window->close();

            /* keyboard input*/
            if (this->event.key.code == sf::Keyboard::W)
                this->inputs.up = true;
            if (this->event.key.code == sf::Keyboard::A)
                this->inputs.left = true;
            if (this->event.key.code == sf::Keyboard::S)
                this->inputs.down = true;
            if (this->event.key.code == sf::Keyboard::D)
                this->inputs.right = true;
            break;
        }
    }
}
void Editor::updateScene()
{
    // this->scene.updateNodes();
}

/* public functions */
void Editor::update(sf::Clock deltaClock)
{
    this->pollEvents();
    ImGui::SFML::Update(*this->window, deltaClock.restart());
    this->updateScene();
}
void Editor::render()
{
    ImGui::ShowDemoWindow();
    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();
    this->window->clear();
    ImGui::SFML::Render(*this->window);
    // this->scene.renderNodes();
    this->window->display();
}

/* accessors */
const bool Editor::running() const
{
    return this->window->isOpen();
}
