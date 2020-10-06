#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "Human.h"
#include "Doctor.h"
#include "InfoDesk.h"

class Field
{
public:
	//green - not infected 
	//blue - doctor
	//red - infected
	Field(const int& humans, const int& doctors, const int& maxX, const int& maxY);
	void updateFrame(const unsigned long& elapsedTime);
	int getInfectedNumber();
	void render(sf::RenderWindow* window);
private:
	void appendHuman();
	void appendDoctor();
	Human* find(Human* target);
	Human* find1(Human* target);
	InfoDesk m_info;
	std::vector<Human> m_humans;
	std::vector<Doctor> m_doctors;
	const int m_maxX;
	const int m_maxY;
}; 

