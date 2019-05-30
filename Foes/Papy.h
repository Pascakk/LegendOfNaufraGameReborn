#pragma once
#include "Foes.h"
#include <iostream>

class Papy : public Foes
{
public:
	Papy(float px, float py, Scene* scene);
	virtual void update(float dt);
};
