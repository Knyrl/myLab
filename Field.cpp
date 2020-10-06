#include "Field.h"

Field::Field(const int& humans, const int& doctors, const int& maxX, const int& maxY):
	m_maxX(maxX),
	m_maxY(maxY)
{
	for (int i = 0; i < humans; i++)
	{
		appendHuman();
	}

	for (int i = 0; i < doctors; i++)
	{
		appendDoctor();
	}
}

void Field::appendHuman()
{
	//srand(time(NULL));
	m_humans.push_back(Human(rand()%m_maxX, rand()%m_maxY, rand()%2));
}

void Field::appendDoctor()
{
	srand(time(NULL));
	m_doctors.push_back(Doctor(rand() % m_maxX, rand() % m_maxY));
}



void Field::updateFrame(const unsigned long& elapsedTime)
{
	for (int i = 0; i < m_humans.size(); i++)
	{
		m_humans[i].updatePosition(20, m_maxX, m_maxY);
		if ((find(&m_humans[i]) != nullptr) && (!m_humans[i].getPlagueState()))
		{
			m_humans[i].setPlagueState(true);
		}
	}
	for (int i = 0; i < m_doctors.size(); i++)
	{
		m_doctors[i].updatePosition(20, m_maxX, m_maxY);
		for (int j = 0; j < m_humans.size(); j++)
		{
			if ((m_humans[j].getPlagueState()) && (find1(&m_humans[j]) != nullptr))
			{
				//findPlagueNearby(&m_humans[i])->setPlagueState(false); // крашит прогу 
				m_humans[j].setPlagueState(false);
			}
		}
	}
}

int Field::getInfectedNumber()
{
	int result(0);
	for (int i = 0; i < m_humans.size(); i++)
	{
		if (m_humans[i].getPlagueState())
		{
			result++;
		}
	}
	return result;
}

void Field::render(sf::RenderWindow* window)
{
	
	for (int i = 0; i < m_humans.size(); i++)
	{
		m_humans[i].render(window);
	}

	for (int i = 0; i < m_doctors.size(); i++)
	{
		m_doctors[i].render(window);
	}

	m_info.render(window);

}


Human* Field::find(Human* target)
{
	for (int i = 0; i < m_humans.size(); i++)
	{
		if (m_humans[i].getPlagueState())
		{
			if ((abs(m_humans[i].getPosX() - target->getPosX()) < target[i].getPlagueRange())
				&& (abs(m_humans[i].getPosY() - target->getPosY()) < target[i].getPlagueRange()))
			{
				return target;
				break;
			}
		}
	}
	return nullptr;
}

Human* Field::find1(Human* target)
{
	for (int i = 0; i < m_doctors.size(); i++)
	{

			if ((abs(m_doctors[i].getPosX() - target->getPosX()) < m_doctors[i].getHealRange())
				&& (abs(m_doctors[i].getPosY() - target->getPosY()) < m_doctors[i].getHealRange()))
			{
				return target;
				break;
			}
	}
	return nullptr;
}

