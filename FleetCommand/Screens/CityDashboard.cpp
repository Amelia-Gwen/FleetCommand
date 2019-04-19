#include "CityDashboard.h"

namespace fleet {
	CityDashboard::CityDashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
		dashboardButton.setLabelOffset(dashboard_x_offset);
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboardButton.setCharacterSize(text_character_size);
		cityMapButton.setLabelOffset(citymap_x_offset);
		cityMapButton.setPosition(game_button_2_x, game_button_y);
		cityMapButton.setCharacterSize(text_character_size);
		cityUpgradeButton.setLabelOffset(cityupgrade_x_offset);
		cityUpgradeButton.setPosition(game_button_3_x, game_button_y);
		cityUpgradeButton.setCharacterSize(text_character_size);
		worldMapButton.setLabelOffset(worldmap_x_offset);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMapButton.setCharacterSize(text_character_size);
	}

	void CityDashboard::setCity(unsigned index, bool owned)
	{
		cityIndex = index;
		cityMapButton.setActive(owned);
		cityUpgradeButton.setActive(owned);
	}

	GameEvent CityDashboard::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.input(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (cityMapButton.input(mousePos)) {
			return GameEvent::GoToCityMap;
		}
		else if (cityUpgradeButton.input(mousePos)) {
			return GameEvent::GoToCityUpgrade;
		}
		else if (worldMapButton.input(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

		return gameEvent;
	}
	void CityDashboard::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		dashboardButton.update(mousePos);
		cityMapButton.update(mousePos);
		cityUpgradeButton.update(mousePos);
		worldMapButton.update(mousePos);
	}
	void CityDashboard::draw()
	{
		window.draw(displayPanel);
		window.draw(dashboardButton);
		window.draw(cityMapButton);
		window.draw(cityUpgradeButton);
		window.draw(worldMapButton);
	}
}