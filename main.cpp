#include "Engine.h"

int main()
{
    Engine engine;
    sf::Clock deltaClock;
    while (engine.running())
    {
        sf::Time dt = deltaClock.restart();
        engine.update(dt.asMilliseconds());
        engine.render();
    }

    return 0;
}