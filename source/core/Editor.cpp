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

    std::shared_ptr<Node> node = this->scene.GetRoot();
    std::vector<int> visited;
    std::queue<std::shared_ptr<Node>> queue;
    visited.push_back(node->id);
    queue.push(node);

    while (!queue.empty())
    {
        node = queue.front();
        queue.pop();
        // std::cout << node->name << std::endl;
        if (ImGui::TreeNode(node->name))
        {
            for (auto &&child : node->GetChildren())
            {
                if (std::find(visited.begin(), visited.end(), child->id) == visited.end())
                {
                    visited.push_back(child->id);
                    queue.push(child);
                    if (ImGui::TreeNode(child->name))
                    {
                        ImGui::TreePop();
                    }
                }
            }
            ImGui::TreePop();
        }
    }

    ImGui::End();
    ImGui::SFML::Render(*this->window);
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
