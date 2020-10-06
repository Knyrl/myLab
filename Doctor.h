#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Human.h"

class Doctor: public Human
{
public:
	Doctor(const int& x, const int& y, const int& healRange = 80, const int& velocity = 1);
	//int getPosX();
	//int getPosY();
	void updatePosition(const int& elapsedTime, const int& maxX, const int& maxY);
	int getHealRange();
	//int getVelocity();
	void render(sf::RenderWindow* window);
private:
	//void setPosition(const int& x, const int& y);
	sf::RectangleShape m_rect;
	int m_HealRange;
	//const int m_velocity;
	//int m_posX;
	//int m_posY;
};

