#include "Editor.h"

/* private functions */
void Editor::initVariables()
{
    this->window = nullptr;
};
void Editor::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "phlawless-engine");
    ImGui::SFML::Init(*this->window);
};

/* constructors */
Editor::Editor()
{
    this->initVariables();
    this->initWindow();
};

Editor::~Editor()
{
    // delete this->window;
    ImGui::SFML::Shutdown();
};

void Editor::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        ImGui::SFML::ProcessEvent(*this->window, this->event);
        switch (this->event.type)
        {

        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape)
                window->close();

            break;
        }
    }
}
void Editor::renderGUI()
{
    ImGui::Begin("Scene");
    renderSceneTreeNode(this->scene.GetRoot());
    ImGui::End();
    ImGui::SFML::Render(*this->window);
}
void Editor::renderSceneTreeNode(std::shared_ptr<Node> node)
{
    bool expanded = ImGui::TreeNodeEx((void *)nullptr, ImGuiTreeNodeFlags_FramePadding, "", nullptr);
    ImGui::SameLine();
    ImGui::Selectable(node->name, this->selectedNode == node->id);
    if (expanded)
    {
        for (auto &&child : node->GetChildren())
        {
            renderSceneTreeNode(child);
        }
        ImGui::TreePop();
    }
}
void Editor::updateScene()
{
    this->scene.updateNodes();
}

/* public functions */
void Editor::update(sf::Clock deltaClock)
{
    this->pollEvents();
    ImGui::SFML::Update(*this->window, deltaClock.restart());
    this->updateScene();
}
void Editor::render()
{

    this->window->clear();
    renderGUI();
    this->scene.renderNodes();
    this->window->display();
}

/* accessors */
const bool Editor::running() const
{
    return this->window->isOpen();
}
