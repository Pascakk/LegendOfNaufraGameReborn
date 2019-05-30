#include "Papy.h"
#include "../Scene.h"

Papy::Papy(float px, float py, Scene* scene): Foes(px, py, 40,40,0,0,0,0,40,15,"DATA/Ressources/Textures/papy_turn_head.png", scene)
{
}

void Papy::update(float dt)
{
	if (m_scene->getCurrentCharac()->getPos().y > getPosition().y && m_scene->getCurrentCharac()->getPos().y < getPosition().y + 300)
	{
		float diff = getPosition().x - m_scene->getCurrentCharac()->getPos().x;
		if (diff < 0)
		{
			if (diff < -100) { orient(0); }
			else { orient(1); }
		}
		else
		{
			if (diff > 100) { orient(4); }
			else { orient(3); }
		}
		if (std::abs(diff) < 30) { orient(2); }
	}
	else { orient(2); }
}
