#include "Baba.h"

Baba::Baba(float px, float py, Scene* scene): Character(px, py, 64,64,0,128,15,0,20,10, "walk.png", scene)
{
	setMaxHealth(100);
	setHealth(100);
	setScale(0.8, 0.8);
}
