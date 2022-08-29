#include "Scene.h"

Scene::Scene()
{
    char *rootName = "Root";
    char *childName = "Child";
    char *childName2 = "Child2";
    this->root = std::make_unique<Node>(rootName);
    for (size_t i = 0; i < 4; i++)
    {
        this->root->AddChild(std::make_unique<Node>(childName));
    }
    for (auto &&child : this->root->GetChildren())
    {
        for (size_t i = 0; i < 4; i++)
        {
            child->AddChild(std::make_unique<Node>(childName2));
        }
    }
}

Scene::~Scene()
{
}
void Scene::updateNodes()
{
    root->Update();
}
void Scene::renderNodes()
{
    root->Render();
}
std::shared_ptr<Node> Scene::GetRoot()
{
    return this->root;
}