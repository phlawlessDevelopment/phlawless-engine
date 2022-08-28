#include "Scene.h"

Scene::Scene(/* args */)
{
}

Scene::~Scene()
{
}
void Scene::updateNodes(){
    root->Update();
}
void Scene::renderNodes(){
    root->Render();
}