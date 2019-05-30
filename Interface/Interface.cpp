#include "Interface.h"

Interface::Interface(float px, float py, int textRect_width, int textRect_height, int textRect_top, int textRect_left, int hitbox_x, int hitbox_y, int hitbox_largeur, int hitbox_hauteur, std::string texture, Scene* scene) :
	Entite(px, py, textRect_width, textRect_height, textRect_top, textRect_left, hitbox_x, hitbox_y, hitbox_largeur, hitbox_hauteur, texture, scene)
{
    //ctor
}

void Interface::update(float dt)
{

}


Interface::~Interface()
{
    //dtor
}
