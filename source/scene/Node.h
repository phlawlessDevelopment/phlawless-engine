#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../components/Component.h"

class Node
{
private:
    std::vector<std::shared_ptr<Component>> components;
    std::vector<std::shared_ptr<Node>> children;
    std::shared_ptr<Node> parent;
        
public:
    /* transform  */
    sf::Vector2f position;
    sf::Vector2f rotation;
    sf::Vector2f scale;


    void Init();
    void Update();
    void Render();

    /* acccesors  */
    std::shared_ptr<Node> GetParent();
    std::shared_ptr<Node> GetNthChild(int n);

    Node();
    ~Node();
};


