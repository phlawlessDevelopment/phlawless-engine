#include "Node.h"

Node::Node(char *name)
{
    this->name = name;
    this->id = ++nextId;
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

    /* update children  */
    for (auto &&child : this->children)
    {
        child->Update();
    }
}

void Node::Render()
{
    /* render  */

    /* render children  */
    for (auto &&child : this->children)
    {
        child->Render();
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