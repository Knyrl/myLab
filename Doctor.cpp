#include "Doctor.h"


Doctor::Doctor(const int& x, const int& y, const int& healRange, const int& velocity):
	Human(x,y,velocity),
	//m_velocity(velocity),
	//m_posX(x),
	//m_posY(y),
	m_HealRange(healRange),
	m_rect(sf::Vector2f(10, 10)) 
{
	m_rect.setFillColor(sf::Color::Blue);
}

//int Doctor::getPosX()
//{
//	return m_posX;
//}
//
//int Doctor::getPosY()
//{
//	return m_posY;
//}

//void Doctor::setPosition(const int& x, const int& y)
//{
//	m_posX = x;
//	m_posY = y;
//	m_rect.setPosition(sf::Vector2f(x, y));
//}


void Doctor::updatePosition(const int& elapsedTime, const int& maxX, const int& maxY)
{
	//srand(time(NULL));
	int randomMove = rand() % 4;
	switch (randomMove)
	{
	case 0:
		m_posY -= elapsedTime * m_velocity;
		if (m_posY < 0)
			m_posY = 0;
		break;
	case 1:
		m_posX += elapsedTime * m_velocity;
		if (m_posX > maxX)
			m_posX = maxX;
		break;
	case 2:
		m_posY += elapsedTime * m_velocity;
		if (m_posY > maxY)
			m_posY = maxY;
		break;
	case 3:
		m_posX -= elapsedTime * m_velocity;
		if (m_posX < 0)
			m_posX = 0;
		break;
	default:
		break;
	}
	m_rect.setPosition(sf::Vector2f(m_posX, m_posY));
}

int Doctor::getHealRange()
{
	return m_HealRange;
}

//int Doctor::getVelocity()
//{
//	return m_velocity;
//}

void Doctor::render(sf::RenderWindow* window)
{
	window->draw(this->m_rect);
}
