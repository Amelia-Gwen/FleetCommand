#include "CityDashboard.h"

namespace fleet {
	CityDashboard::CityDashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboard.setPosition(game_button_1_x + dashboard_x_offset, game_button_text_y);
		dashboard.setCharacterSize(text_character_size);
		dashboard.setFillColor(sf::Color::Black);
		cityMapButton.setPosition(game_button_2_x, game_button_y);
		cityMap.setPosition(game_button_2_x + citymap_x_offset, game_button_text_y);
		cityMap.setCharacterSize(text_character_size);
		cityMap.setFillColor(sf::Color::Black);
		cityUpgradeButton.setPosition(game_button_3_x, game_button_y);
		cityUpgrade.setPosition(game_button_3_x + cityupgrade_x_offset, game_button_text_y);
		cityUpgrade.setCharacterSize(text_character_size);
		cityUpgrade.setFillColor(sf::Color::Black);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMap.setPosition(game_button_4_x + worldmap_x_offset, game_button_text_y);
		worldMap.setCharacterSize(text_character_size);
		worldMap.setFillColor(sf::Color::Black);
	}

	void CityDashboard::setCity(unsigned index)
	{
		cityIndex = index;
	}

	GameEvent CityDashboard::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (cityMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToCityMap;
		}
		else if (cityUpgradeButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToCityUpgrade;
		}
		else if (worldMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

		return gameEvent;
	}
	void CityDashboard::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		checkMouseOver(dashboardButton);
		checkMouseOver(cityMapButton);
		checkMouseOver(cityUpgradeButton);
		checkMouseOver(worldMapButton);
	}
	void CityDashboard::draw()
	{
		window.draw(displayPanel);
		window.draw(dashboardButton);
		window.draw(dashboard);
		window.draw(cityMapButton);
		window.draw(cityMap);
		window.draw(cityUpgradeButton);
		window.draw(cityUpgrade);
		window.draw(worldMapButton);
		window.draw(worldMap);
	}
}