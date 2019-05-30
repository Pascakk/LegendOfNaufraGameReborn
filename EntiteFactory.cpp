#include "EntiteFactory.h"
#include <iostream>

EntiteFactory::EntiteFactory()
{

}



Entite* EntiteFactory::createEntite(float px, float py, Scene* scene, std::string className)
{
	if (className == "Arbre")
	{
		return new Arbre(px, py, scene);
	}

	else if (className == "Maison")
	{
		return new Maison(px, py, scene);
	}
	else if (className == "Echoppe")
	{
		return new Echoppe(px, py, scene);
	}
	else if (className == "Papy")
	{
		return new Papy(px, py, scene);
	}
	else if (className == "Sbire")
	{
		return new Sbire(px, py, scene);
	}
	else
	{
		std::cout << "ERROR ENTITEFACTORY DECOR INCONNU" << std::endl;
		return NULL;
	}

}

Character* EntiteFactory::createCharacter(float px, float py, Scene* scene, std::string className)
{
	if (className == "Baba")
	{
		return new Baba(px, py, scene);
	}
	else
	{
		std::cout << "ERROR ENTITEFACTORY CHARACTER INCONNU" << std::endl;
		return NULL;
	}
}
