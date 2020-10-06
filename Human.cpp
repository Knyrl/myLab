#include "Human.h"

Human::Human(const int& x, const int& y, const bool& status, const int& plagueRange, const int& velocity) :
	m_posX(x),
	m_posY(y),
	m_velocity(velocity),
	m_plagueRange(plagueRange),
	m_plagueStatus(status),
	m_rect(sf::Vector2f(10, 10))
{
	if (status)
		m_rect.setFillColor(sf::Color::Red);
	else
		m_rect.setFillColor(sf::Color::Green);
}

int Human::getPosX()
{
	return m_posX;
}

int Human::getPosY()
{
	return m_posY;
}

void Human::setPosition(const int& x, const int& y)
{
	m_posX = x;
	m_posY = y;
	m_rect.setPosition(sf::Vector2f(x, y));
}

void Human::updatePosition(const int& elapsedTime, const int& maxX, const int& maxY)
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

int Human::getPlagueRange()
{
	return m_plagueRange;
}

bool Human::getPlagueState()
{
	return m_plagueStatus;
}

int Human::getVelocity()
{
	return m_velocity;
}

void Human::setPlagueState(const bool& status)
{
	m_plagueStatus = status;
	if (status)
		m_rect.setFillColor(sf::Color::Red);
	else
		m_rect.setFillColor(sf::Color::Green);
}

void Human::render(sf::RenderWindow* window)
{
	window->draw(this->m_rect);
}
