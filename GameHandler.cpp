#include "GameHandler.h"

GameHandler::GameHandler(sf::RenderWindow* window) : m_window(window)
{

}

void GameHandler::addScene(std::string fichier_tilemap, Character* currentCharac)
{
    std::cout << "creation de la scene " << fichier_tilemap << std::endl;
    m_scenes.push_back(new Scene(fichier_tilemap, currentCharac));
    currentCharac->setScene(m_scenes[0]);
}

void GameHandler::update(float dt)
{
    for (int i(0); i < m_scenes.size(); i++)
	{
		Scene* currentScene(m_scenes[i]);
		currentScene->update(dt);
    }
}

void GameHandler::draw()
{
    for (int i(0); i < m_scenes.size(); i++)
	{
		Scene* currentScene(m_scenes[i]);
		currentScene->draw(m_window);
    }
    for (int i(0); i < m_menus.size(); i++)
	{
		Scene* currentMenu(m_menus[i]);
		currentMenu->draw(m_window);
    }

}

std::vector<Scene*>* GameHandler::getCurrentScenes()
{
    return &m_scenes;
}

void GameHandler::clearScenes()
{
    m_scenes.clear();
}

GameHandler::~GameHandler()
{
    for (int i(0); i < m_scenes.size(); i++)
	{
		delete m_scenes[i];
	}
    for (int i(0); i < m_menus.size(); i++)
	{
		delete m_menus[i];
    }
}
