#include "CityUpgradeScreen.h"

namespace fleet {
	CityUpgradeScreen::CityUpgradeScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboard.setPosition(game_button_1_x + dashboard_x_offset, game_button_text_y);
		dashboard.setCharacterSize(text_character_size);
		dashboard.setFillColor(sf::Color::Black);
		cityDashboardButton.setPosition(game_button_2_x, game_button_y);
		cityDashboard.setPosition(game_button_2_x + cityname_x_offset, game_button_text_y);
		cityDashboard.setCharacterSize(text_character_size);
		cityDashboard.setFillColor(sf::Color::Black);
		cityMapButton.setPosition(game_button_3_x, game_button_y);
		cityMap.setPosition(game_button_3_x + citymap_x_offset, game_button_text_y);
		cityMap.setCharacterSize(text_character_size);
		cityMap.setFillColor(sf::Color::Black);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMap.setPosition(game_button_4_x + worldmap_x_offset, game_button_text_y);
		worldMap.setCharacterSize(text_character_size);
		worldMap.setFillColor(sf::Color::Black);

		shipyard.setPosition(city_upgrade_column_one_x, city_upgrade_row_one_y);
		shipyard.setFont(font);
		airDefense.setPosition(city_upgrade_column_two_x, city_upgrade_row_one_y);
		airDefense.setFont(font);
		groundDefense.setPosition(city_upgrade_column_three_x, city_upgrade_row_one_y);
		groundDefense.setFont(font);
		oilProduction.setPosition(city_upgrade_column_one_x, city_upgrade_row_two_y);
		oilProduction.setFont(font);
		cashProduction.setPosition(city_upgrade_column_one_x, city_upgrade_row_two_y);
		cashProduction.setFont(font);
		researchProduction.setPosition(city_upgrade_column_one_x, city_upgrade_row_two_y);
		researchProduction.setFont(font);
	}

	void CityUpgradeScreen::setCity(unsigned index)
	{
		cityName = model.cityList()[index].cityName();
		cityDashboard.setString(cityName);
		// set appropriate upgrade levels
	}

	GameEvent CityUpgradeScreen::input()
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
		else if (cityMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToCityMap;
		}
		else if (worldMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

		return gameEvent;
	}
	void CityUpgradeScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		checkMouseOver(dashboardButton);
		checkMouseOver(cityDashboardButton);
		checkMouseOver(cityMapButton);
		checkMouseOver(worldMapButton);
	}
	void CityUpgradeScreen::draw()
	{
		window.draw(displayPanel);
		window.draw(dashboardButton);
		window.draw(dashboard);
		window.draw(cityDashboardButton);
		window.draw(cityDashboard);
		window.draw(cityMapButton);
		window.draw(cityMap);
		window.draw(worldMapButton);
		window.draw(worldMap);
		window.draw(shipyard);
		window.draw(airDefense);
		window.draw(groundDefense);
		window.draw(oilProduction);
		window.draw(cashProduction);
		window.draw(researchProduction);
	}
}