#include "Engine.h"

/* private functions */
void Engine::initVariables()
{
    this->window = nullptr;
};
void Engine::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "phlawless-engine");
};

/* constructors */
Engine::Engine()
{
    this->initVariables();
    this->initWindow();
};

Engine::~Engine()
{
    delete this->window;
};

void Engine::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {

        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape)
                window->close();
            /* keyboard input*/
            break;
        }
    }
}
/* public functions */
void Engine::update()
{
    this->pollEvents();
}
void Engine::render()
{
    this->window->clear();

    /* draw game objects */

    this->window->display();
}

/* accessors */
const bool Engine::running() const
{
    return this->window->isOpen();
}