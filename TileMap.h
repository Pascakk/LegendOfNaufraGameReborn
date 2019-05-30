#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Tuile.h"
#include "Character/Character.h"
#include "EntiteFactory.h"

class TileMap
{
public:
    TileMap(std::string fichier);
	bool load();
	std::vector<Tuile*> getTabTuile() const;
	std::string getTileMapFileName() const;
	~TileMap();

protected:
	std::vector<int> loadTileMapFile(std::string fichier);
	sf::Texture m_tileset;
	//Tableau element graphique contenant des pointeurs Tuiles (polymorphisme)
	std::vector<Tuile*> m_pTabTuile;
	std::string m_tileMapFile;
	std::string m_tilesetFile;
	std::string m_entiteFileName;
	sf::Vector2u m_tileSize;
	int m_largeur;
	int m_hauteur;

};
