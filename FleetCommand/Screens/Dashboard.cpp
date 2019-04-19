#include "Dashboard.h"

namespace fleet {
	Dashboard::Dashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
		unitsButton.setLabelOffset(unit_x_offset);
		unitsButton.setPosition(game_button_1_x, game_button_y);
		unitsButton.setCharacterSize(text_character_size);
		researchButton.setLabelOffset(research_x_offset);
		researchButton.setPosition(game_button_2_x, game_button_y);
		researchButton.setCharacterSize(text_character_size);
		fleetButton.setLabelOffset(fleet_x_offset);
		fleetButton.setPosition(game_button_3_x, game_button_y);
		fleetButton.setCharacterSize(text_character_size);
		worldMapButton.setLabelOffset(worldmap_x_offset);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMapButton.setCharacterSize(text_character_size);
	}
	GameEvent Dashboard::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (unitsButton.input(mousePos)) {
			return GameEvent::GoToUnits;
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
	void Dashboard::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		unitsButton.update(mousePos);
		researchButton.update(mousePos);
		fleetButton.update(mousePos);
		worldMapButton.update(mousePos);
	}
	void Dashboard::draw()
	{
		window.draw(displayPanel);
		window.draw(unitsButton);
		window.draw(researchButton);
		window.draw(fleetButton);
		window.draw(worldMapButton);
	}
}