#include "FleetScreen.h"

namespace fleet {
	FleetScreen::FleetScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
		dashboardButton.setLabelOffset(dashboard_x_offset);
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboardButton.setCharacterSize(text_character_size);
		researchButton.setLabelOffset(research_x_offset);
		researchButton.setPosition(game_button_2_x, game_button_y);
		researchButton.setCharacterSize(text_character_size);
		unitsButton.setLabelOffset(unit_x_offset);
		unitsButton.setPosition(game_button_3_x, game_button_y);
		unitsButton.setCharacterSize(text_character_size);
		worldMapButton.setLabelOffset(worldmap_x_offset);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMapButton.setCharacterSize(text_character_size);
	}

	GameEvent FleetScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.input(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (researchButton.input(mousePos)) {
			return GameEvent::GoToResearch;
		}
		else if (unitsButton.input(mousePos)) {
			return GameEvent::GoToUnits;
		}
		else if (worldMapButton.input(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

		return gameEvent;
	}
	void FleetScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		dashboardButton.update(mousePos);
		researchButton.update(mousePos);
		unitsButton.update(mousePos);
		worldMapButton.update(mousePos);
	}
	void FleetScreen::draw()
	{
		window.draw(displayPanel);
		window.draw(dashboardButton);
		window.draw(researchButton);
		window.draw(unitsButton);
		window.draw(worldMapButton);
	}
}