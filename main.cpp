#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Field.h"

constexpr int HUMANS_NUMBER(20);
constexpr int DOCTORS_NUMBER(10);
constexpr int MAX_X(790);
constexpr int MAX_Y(790);
constexpr int MAX_TIME(60);
constexpr int WIN_X(800);
constexpr int WIN_Y(800);

int main()
{
	srand(time(NULL));
	Field* myField;
	myField = new Field(HUMANS_NUMBER, DOCTORS_NUMBER, MAX_X, MAX_Y);
	float deltaTime(0.f);
	float elapsedTime(0.f);
	sf::Clock timer;

	sf::RenderWindow window(sf::VideoMode(WIN_X, WIN_Y), "PlagueInc for homeless");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		while (static_cast<int>(elapsedTime) < MAX_TIME)
		{
			deltaTime = timer.restart().asSeconds();
			elapsedTime += deltaTime;
			for (sf::Event event; window.pollEvent(event);)
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}

			myField->updateFrame(deltaTime);
			if (myField->getInfectedNumber() == HUMANS_NUMBER) 
			//if (false)
			{
				std::cout << "All humans is plague in " << static_cast<int>(elapsedTime) << " seconds!" << std::endl;
			window.close();
				return 0;
			}
			if (myField->getInfectedNumber() == 0)
			//if (false)
			{
				std::cout << "Plague defeated in " << static_cast<int>(elapsedTime) << " seconds!" << std::endl;
			window.close();
				return 0;
			}
			window.clear();
			myField->render(&window);
			window.display();
			
		}
		std::cout << "DRAW!" << std::endl;
		window.close();
		return 0;
	}
}