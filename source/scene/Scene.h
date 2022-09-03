#include <vector>
#include <memory>
#include "Node.h"

class Scene
{
private:
    std::shared_ptr<Node> root;
public:
    Scene(/* args */);
    ~Scene();
    
    void updateNodes();
    void renderNodes(sf::RenderWindow* window);

    /* accessors */
    std::shared_ptr<Node> GetRoot();
    std::shared_ptr<Node> GetNodeById(std::shared_ptr<Node> node , int id);
};
