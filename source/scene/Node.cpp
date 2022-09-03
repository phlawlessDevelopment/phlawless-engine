#include "Node.h"

Node::Node(char *name)
{
    this->name = name;
    this->id = ++nextId;
    this->positionGizmo = sf::CircleShape(10.0f);
}

Node::~Node()
{

}

void Node::Init()
{

}

void Node::Update()
{
    /* update  logic  */
    this->positionGizmo.setPosition(this->position);
    /* update children  */
    for (auto &&child : this->children)
    {
        child->Update();
    }
}

void Node::Render(sf::RenderWindow* window)
{
    /* render  */
    window->draw(this->positionGizmo);
    /* render children  */
    for (auto &&child : this->children)
    {
        child->Render(window);
    }
}
void Node::AddChild(std::shared_ptr<Node> node){
    this->children.push_back(node);
}
/* acccesors  */
std::vector<std::shared_ptr<Node>> Node::GetChildren(){
    return children;
}
std::shared_ptr<Node> Node::GetParent()
{
    return parent;
}
std::shared_ptr<Node> Node::GetNthChild(int n)
{
    return children[n];
}