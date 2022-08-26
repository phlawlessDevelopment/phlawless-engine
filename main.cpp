#include "Engine.h"

int main()
{
    Engine engine;

    while (engine.running())
    {
        engine.update();
        engine.render();
    }

    return 0;
}