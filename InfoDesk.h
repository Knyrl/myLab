#pragma once

#include <SFML/Graphics.hpp>

class InfoDesk
{
public:
	InfoDesk(unsigned int chSize = 10u, float height = 40, float width = 100, sf::Color bgColor = sf::Color(0, 45, 0), sf::Color textColor = sf::Color::White);
	void render(sf::RenderWindow* window);
	void setPosition(float x, float y);
	float getX();
	float getY();
private:
	void updateInfo();
	sf::Color m_bgColor;
	sf::Color m_textColor;
	float m_width;
	float m_height;
	float m_x;
	float m_y;
	sf::Text m_text;
	sf::RectangleShape m_base;
};

