#include "UnitScreen.h"

namespace fleet {
	UnitScreen::UnitScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
		dashboardButton.setLabelOffset(sf::Vector2f(dashboard_x_offset, game_text_y_offset));
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboardButton.setCharacterSize(text_character_size);
		researchButton.setLabelOffset(sf::Vector2f(research_x_offset, game_text_y_offset));
		researchButton.setPosition(game_button_2_x, game_button_y);
		researchButton.setCharacterSize(text_character_size);
		fleetButton.setLabelOffset(sf::Vector2f(fleet_x_offset, game_text_y_offset));
		fleetButton.setPosition(game_button_3_x, game_button_y);
		fleetButton.setCharacterSize(text_character_size);
		worldMapButton.setLabelOffset(sf::Vector2f(worldmap_x_offset, game_text_y_offset));
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMapButton.setCharacterSize(text_character_size);
	}

	GameEvent UnitScreen::input()
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
		else if (fleetButton.input(mousePos)) {
			return GameEvent::GoToFleet;
		}
		else if (worldMapButton.input(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

		return gameEvent;
	}
	void UnitScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		dashboardButton.update(mousePos);
		researchButton.update(mousePos);
		fleetButton.update(mousePos);
		worldMapButton.update(mousePos);
	}
	void UnitScreen::draw()
	{
		window.draw(displayPanel);
		window.draw(dashboardButton);
		window.draw(researchButton);
		window.draw(fleetButton);
		window.draw(worldMapButton);
	}
}