#include "Node.h"

Node::Node()
{
    
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
/* acccesors  */
std::shared_ptr<Node> Node::GetParent()
{
    return parent;
}
std::shared_ptr<Node> Node::GetNthChild(int n)
{
    return children[n];
}