#include "Scene.h"

Scene::Scene(std::string fichier_tilemap, Character* currentCharac) : m_fichier_tilemap(fichier_tilemap), m_currentCharac(currentCharac)
{
    m_tileMap = new TileMap(fichier_tilemap);
    m_currentCharac->setZorder(0);
    m_pTabEntite.push_back(m_currentCharac);
    m_pTabEntite[0]->test_poly();
    loadEntiteFile();
    m_pTabTuile = m_tileMap->getTabTuile();
}

Scene::~Scene()
{
    for (int i(0); i < m_pTabEntite.size(); i++)
	{
		//On detruit tous les pointeurs fait en allocation dynamique
		delete m_pTabEntite[i];
	}
}

Character* Scene::getCurrentCharac() const
{
	return m_currentCharac;
}

std::vector<Entite*> Scene::getTabEntite() const
{
	return m_pTabEntite;
}

void Scene::addEntiteMoved(Entite* entite)
{
	m_pTabEntiteMoved.push_back(entite);
}

void Scene::update(float dt)
/*Trie par z-order toutes les entités qui ont bougés a partir du tableau m_pTabEntiteMoved, et du tableau m_pTabEntite contenant toutes les entités triés a l'instant t-dt*/
{
	for (int i(0); i < m_pTabEntiteMoved.size(); i++)
	{
		bool trie(false);
		Entite* currentEntite(m_pTabEntiteMoved[i]);
		int zorder(currentEntite->getZorder());
		while (!trie)
		{
			if (zorder+1 < m_pTabEntite.size() && currentEntite->getPosition().y > m_pTabEntite[zorder + 1]->getPosition().y)
			{

				Entite* entite1 = m_pTabEntite[zorder];
				Entite* entite2 = m_pTabEntite[zorder+1];
				m_pTabEntite[zorder]->setZorder(zorder + 1);
				m_pTabEntite[zorder + 1]->setZorder(zorder);
				m_pTabEntite[zorder] = entite2;
				m_pTabEntite[zorder + 1] = entite1;
				std::cout << "ON AUGMENTE LE ZORDER" << std::endl;
			}
			else if (zorder > 0 && currentEntite->getPosition().y < m_pTabEntite[zorder - 1]->getPosition().y)
			{
				Entite* entite1 = m_pTabEntite[zorder];
				Entite* entite2 = m_pTabEntite[zorder - 1];
				m_pTabEntite[zorder]->setZorder(zorder - 1);
				m_pTabEntite[zorder - 1]->setZorder(zorder);
				m_pTabEntite[zorder] = entite2;
				m_pTabEntite[zorder - 1] = entite1;
				std::cout << "ON BAISSE LE ZORDER" << std::endl;
			}
			else
			{
				trie = true;
			}
			zorder = currentEntite->getZorder();
		}
	}
    for (int i(0); i < m_pTabEntite.size(); i++)
    {
        //mise à jour des entités
        m_pTabEntite[i]->update(dt);
    }
}

void Scene::draw(sf::RenderWindow* window) const
{
    //AFFICHAGE
    for (int i(0); i < m_pTabTuile.size(); i++)
    {
        //affichage des tuiles
        window->draw(*m_pTabTuile[i]);
    }
    for (int i(0); i < m_pTabEntite.size(); i++)
    {
        //Affichage des entités
        window->draw(*m_pTabEntite[i]);
    }
}

void Scene::loadEntiteFile()
/*Charge le fichier txt des entités et initialise m_pTabEntite tableau contenant des pointeurs vers toutes les entités trié par z-order croissant*/
{
	std::ifstream entiteFile(m_tileMap->getTileMapFileName(), std::ios::in);
	if (entiteFile)
	{
		std::string ligne; //Ligne pour la lecture ligne par ligne
		int iData(0);
		int jEntite(1); //On commence a 1 car 0 est utilisé pour le perso (pour l'instant)

		int x(0);
		int y(0);
		int zorder(0);
		std::string className("");

		while (std::getline(entiteFile, ligne))
		{
			if (iData == 0)
			{
				std::cout << ligne << std::endl;
				className = ligne;
				iData++;
			}
			else if (iData == 1)
			{
				std::cout << ligne << std::endl;
				x = std::stoi(ligne);
				iData++;
			}
			else if (iData == 2)
			{
				std::cout << ligne << std::endl;
				y = std::stoi(ligne);
				m_pTabEntite.push_back(EntiteFactory::createEntite(x, y, this, className));
				iData++;
			}
			else if (iData == 3)
			{
				std::cout << ligne << std::endl;
				zorder = std::stoi(ligne);
				iData = 0;
				m_pTabEntite[jEntite]->setZorder(zorder);
				jEntite++;
			}


		}
	}
	else
	{
		std::cout << "Impossible d'ouvrir le fichier des entites" << std::endl;
	}
}




