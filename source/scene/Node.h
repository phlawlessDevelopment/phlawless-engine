#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../components/Component.h"

class Node
{

protected:
    inline static int nextId;

private:
    std::vector<std::shared_ptr<Component>> components;
    std::vector<std::shared_ptr<Node>> children;
    std::shared_ptr<Node> parent;
    sf::CircleShape positionGizmo;

public:
    char *name;
    /* transform  */
    sf::Vector2f position;
    sf::Vector2f rotation;
    sf::Vector2f scale;

    void Init();
    void Update();
    void Render(sf::RenderWindow* window);
    void AddChild(std::shared_ptr<Node> node);

    /* acccesors  */
    std::vector<std::shared_ptr<Node>> GetChildren();
    std::shared_ptr<Node> GetParent();
    std::shared_ptr<Node> GetNthChild(int n);

    int id;

    Node(char *name);
    ~Node();
};
