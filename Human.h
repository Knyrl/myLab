#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <SFML/Graphics.hpp>

class Human
{
public:
	Human(const int& x, const int& y, const bool& status, const int& plagueRange = 80, const int& velocity = 1);
	int getPosX();
	int getPosY();
	int getPlagueRange();
	bool getPlagueState();
	int getVelocity();
	void setPlagueState(const bool& status);
	void updatePosition(const int& elapsedTime, const int& maxX, const int& maxY);
	void render(sf::RenderWindow* window);
	int m_posX;
	int m_posY;
	const int m_velocity;
private:
	void setPosition(const int& x, const int& y);
	sf::RectangleShape m_rect;
	bool m_plagueStatus;
	const int m_plagueRange;
};


