#include <vector>
#include <memory>
#include "Node.h"

class Scene
{
private:
    std::shared_ptr<Node> root;
    /* data */
public:
    Scene(/* args */);
    ~Scene();

    void updateNodes();
    void renderNodes();
};
