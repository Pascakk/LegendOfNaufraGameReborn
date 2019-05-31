#pragma once
#include "Scene.h"

class Scene;

class GameHandler
{
    public:
        GameHandler(sf::RenderWindow* window);
        virtual ~GameHandler();
        std::vector<Scene*>* getCurrentScenes();
        void update(float dt);
        void draw();
        void addScene(std::string fichier_tilemap, Character* currentCharac);
        void clearScenes();
        // SetUI(Scene* scene);
        //Scene* GetUI();

    protected:
        std::vector<Scene*> m_scenes;
        std::vector<Scene*> m_menus;
        sf::RenderWindow* m_window;

    private:
};
