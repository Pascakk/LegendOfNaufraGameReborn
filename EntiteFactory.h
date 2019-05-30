#pragma once
#include <string>

/*CHARACTER*/
#include "Character/Baba.h"

/* DECOR */
#include "Decors/Arbre.h"
#include "Decors/Maison.h"
#include "Decors/Echoppe.h"

/* FOES */
#include "Foes/Papy.h"
#include "Foes/Sbire.h"

class Scene;


class EntiteFactory
{
	public:
		EntiteFactory();
		static Entite* createEntite(float px, float py, Scene* scene, std::string className);
		static Character* createCharacter(float px, float py, Scene* scene, std::string className);

	private:
};
