#include "CityMapScreen.h"

namespace fleet {
	CityMapScreen::CityMapScreen(sf::RenderWindow& window, const sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		cityMap.setPosition(0.F, panel_box_height);
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboard.setPosition(game_button_1_x + dashboard_x_offset, game_button_text_y);
		dashboard.setCharacterSize(text_character_size);
		dashboard.setFillColor(sf::Color::Black);
		cityDashboardButton.setPosition(game_button_2_x, game_button_y);
		cityDashboard.setPosition(game_button_2_x + citymap_x_offset, game_button_text_y);
		cityDashboard.setCharacterSize(text_character_size);
		cityDashboard.setFillColor(sf::Color::Black);
		cityUpgradeButton.setPosition(game_button_3_x, game_button_y);
		cityUpgrade.setPosition(game_button_3_x + cityupgrade_x_offset, game_button_text_y);
		cityUpgrade.setCharacterSize(text_character_size);
		cityUpgrade.setFillColor(sf::Color::Black);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMap.setPosition(game_button_4_x + worldmap_x_offset, game_button_text_y);
		worldMap.setCharacterSize(text_character_size);
		worldMap.setFillColor(sf::Color::Black);
	}

	void CityMapScreen::setCity(unsigned index)
	{
		cityName = model.cityList()[index].cityName();
		cityDashboard.setString(cityName);
		// set city layout
	}

	GameEvent CityMapScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (cityDashboardButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::OpenCity;
		}
		else if (cityUpgradeButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToCityUpgrade;
		}
		else if (worldMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

        gameEvent = cityMap.input(mousePos);

		return gameEvent;
	}
	void CityMapScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		cityMap.update(mousePos);
		displayPanel.update(mousePos);
		checkMouseOver(dashboardButton);
		checkMouseOver(cityDashboardButton);
		checkMouseOver(cityUpgradeButton);
		checkMouseOver(worldMapButton);
	}
	void CityMapScreen::draw()
	{
		window.draw(cityMap);
		window.draw(displayPanel);
		window.draw(dashboardButton);
		window.draw(dashboard);
		window.draw(cityDashboardButton);
		window.draw(cityDashboard);
		window.draw(cityUpgradeButton);
		window.draw(cityUpgrade);
		window.draw(worldMapButton);
		window.draw(worldMap);
	}
}