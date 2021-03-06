#pragma once
#include "SFML/Graphics.hpp"
#include "../Entite.h"
#include <iostream>

class Character: public Entite
{
public:
	Character(float px, float py, int textRect_width, int textRect_height, int textRect_top, int textRect_left, int hitbox_x, int hitbox_y, int hitbox_largeur, int hitbox_hauteur, std::string texture, Scene* scene);
	void update(float dt);
	sf::Vector2f getPos() const;
	void attack(sf::Vector2f vect);
	void setMode(std::string mode);
	std::string getMode();
	void test_poly() const;
	~Character();

protected:
	sf::Texture m_texture;
	float m_acc; //acc�l�ration
	float m_vmax; //vitesse de pointe
	float m_spx; //save posx
	float m_spy; //save poy
	std::string m_mode; //combat ou exploration
	sf::Vector2f m_walkInput;
};

