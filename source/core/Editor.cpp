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
    this->selectedNode = scene.GetNodeById(scene.GetRoot(), this->selectedNodeId);
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
    renderDetails();
    ImGui::SFML::Render(*this->window);
}
void Editor::renderDetails()
{
    ImGui::Begin("Details");
    ImGui::InputFloat2(this->selectedNode->name, &this->selectedNode->position.x);
    ImGui::End();
}
void Editor::renderSceneTreeNode(std::shared_ptr<Node> node)
{
    ImGui::PushID(node->id);
    bool expanded = ImGui::TreeNodeEx((void *)nullptr, ImGuiTreeNodeFlags_FramePadding, "", nullptr);
    ImGui::SameLine();
    ImGui::Selectable(node->name, this->selectedNodeId == node->id);
    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
    {
        this->selectedNodeId = node->id;
        selectedNode = scene.GetNodeById(scene.GetRoot(), this->selectedNodeId);
    }
    if (expanded)
    {
        for (auto &&child : node->GetChildren())
        {
            renderSceneTreeNode(child);
        }
        ImGui::TreePop();
    }
    ImGui::PopID();
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
    this->scene.renderNodes(this->window);
    renderGUI();
    this->window->display();
}

/* accessors */
const bool Editor::running() const
{
    return this->window->isOpen();
}
