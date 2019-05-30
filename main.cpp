#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Entite.h"
#include "TileMap.h"
#include "Scene.h"
#include "Character/Baba.h"
#include "EntiteFactory.h"

int main()
{
	//paramètrage de la fenêtre
	int resoX(800);
	int resoY(600);
	sf::RenderWindow window(sf::VideoMode(resoX, resoY), "NaufraGame tests SFML");
    sf::RenderStates states;

	sf::Vector2f center; //centre de l'écran
	int xborder(1500); //limites de la map (temporaire
	int yborder(1500);

    Character* baba = EntiteFactory::createCharacter(10, 10, nullptr, "Baba");
	Scene scene_depart("tileset0_doc.txt", baba);
    baba->setScene(&scene_depart);

	sf::Clock clock;
	sf::View camera;

	while (window.isOpen())
	{
		window.setView(camera);
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
            {
				window.close();
			}
		}
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//mise à jour de la scène
		window.clear(sf::Color::White);
        scene_depart.draw(&window);
        scene_depart.update(dt);
		window.display();
	}

	return 0;
}

