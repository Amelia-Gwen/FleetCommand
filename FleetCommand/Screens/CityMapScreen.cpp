#include "CityMapScreen.h"

namespace fleet {
	CityMapScreen::CityMapScreen(sf::RenderWindow& window, const sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		cityMap.setPosition(0.F, panel_box_height);
		dashboardButton.setLabelOffset(dashboard_x_offset);
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboardButton.setCharacterSize(text_character_size);
		cityDashboardButton.setLabelOffset(cityname_x_offset);
		cityDashboardButton.setPosition(game_button_2_x, game_button_y);
		cityDashboardButton.setCharacterSize(text_character_size);
		cityUpgradeButton.setLabelOffset(cityupgrade_x_offset);
		cityUpgradeButton.setPosition(game_button_3_x, game_button_y);
		cityUpgradeButton.setCharacterSize(text_character_size);
		worldMapButton.setLabelOffset(worldmap_x_offset);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMapButton.setCharacterSize(text_character_size);
	}

	void CityMapScreen::setCity(unsigned index)
	{
		cityName = model.cityList()[index].cityName();
		cityDashboardButton.setLabel(cityName);
		// set city layout
	}

	GameEvent CityMapScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.input(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (cityDashboardButton.input(mousePos)) {
			return GameEvent::OpenCity;
		}
		else if (cityUpgradeButton.input(mousePos)) {
			return GameEvent::GoToCityUpgrade;
		}
		else if (worldMapButton.input(mousePos)) {
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
		dashboardButton.update(mousePos);
		cityDashboardButton.update(mousePos);
		cityUpgradeButton.update(mousePos);
		worldMapButton.update(mousePos);
	}
	void CityMapScreen::draw()
	{
		window.draw(cityMap);
		window.draw(displayPanel);
		window.draw(dashboardButton);
		window.draw(cityDashboardButton);
		window.draw(cityUpgradeButton);
		window.draw(worldMapButton);
	}
}