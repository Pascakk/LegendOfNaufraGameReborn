#pragma once

#include "TileMap.h"
#include "Entite.h"

class Scene
{
    public:
        Scene(std::string fichier_tilemap, Character* currentCharac);
        ~Scene();
        std::vector<Entite*> getTabEntite() const;
        Character* getCurrentCharac() const;
        void addEntiteMoved(Entite* entite);
        void loadEntiteFile();
        void draw(sf::RenderWindow* window) const;
        void update(float dt);

    protected:
        std::vector<Entite*> m_pTabEntite;
        std::vector<Entite*> m_pTabEntiteMoved;
        std::vector<Tuile*> m_pTabTuile;
        Character* m_currentCharac;
        TileMap* m_tileMap;
        std::string m_fichier_tilemap;
    private:
};


