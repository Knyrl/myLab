#include "InfoDesk.h"

InfoDesk::InfoDesk(unsigned int chSize, float height, float width, sf::Color bgColor, sf::Color textColor):
	m_bgColor(bgColor),
	m_textColor(textColor),
	m_width(width),
	m_height(height)
{
	m_base.setSize(sf::Vector2f(width, height));
	m_text.setCharacterSize(chSize);
	m_base.setFillColor(bgColor);
	//m_text.setFillColor(textColor);
	m_text.setColor(textColor);
	// я не помню какая из этих двух функций цвет текста выбирает
}

void InfoDesk::updateInfo()
{
	std::string docInfo("Number of doctors: ");
	std::string healthInfo("Number of healthy: ");
	std::string plagueInfo("Number of infected: ");
	std::string timeInfo("Elapsed time: ");
	

	
}

void InfoDesk::render(sf::RenderWindow* window)
{
	updateInfo();
	window->draw(m_base);
	window->draw(m_text);
}

void InfoDesk::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	m_base.setPosition(sf::Vector2f(x, y));
	m_text.setPosition(sf::Vector2f(x, y));
}

float InfoDesk::getX()
{
	return m_x;
}

float InfoDesk::getY()
{
	return m_y;
}

