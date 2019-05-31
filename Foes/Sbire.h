#pragma once
#include "Foes.h"
#include <iostream>
class Sbire : public Foes
{
public:
	Sbire(float px, float py, Scene* scene);
	virtual void update(float dt);
protected:
	int m_pos;
	float m_time;
	std::string m_state;
};
