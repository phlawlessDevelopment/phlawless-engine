#include "Editor.h"

int main()
{
    Editor editor;
    sf::Clock deltaClock;
    while (editor.running())
    {
        editor.update(deltaClock);
        editor.render();
    }

    return 0;
}