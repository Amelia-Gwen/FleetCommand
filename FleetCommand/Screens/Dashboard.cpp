#include "Dashboard.h"

namespace fleet {
	Dashboard::Dashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
	}
	GameEvent Dashboard::input()
	{
		return GameEvent();
	}
	void Dashboard::update()
	{
	}
	void Dashboard::draw()
	{
	}
}