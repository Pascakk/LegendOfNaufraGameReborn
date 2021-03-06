#pragma once
#include <SFML/Graphics.hpp>
#include "Entite.h"

class Tuile : public Entite
{
public:
	Tuile(sf::VertexArray quad, sf::Texture* texture, int id);
	~Tuile();
	sf::Texture* getTexture() const;
	void update(float dt);
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_quad;
	sf::Texture* m_texture; //Pointeur vers la texture de la tilesheet
	int m_id;
};
