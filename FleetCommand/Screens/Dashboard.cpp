#include "Dashboard.h"

namespace fleet {
	Dashboard::Dashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
		unitsButton.setPosition(game_button_1_x, game_button_y);
		units.setPosition(game_button_1_x + unit_x_offset, game_button_text_y);
		units.setCharacterSize(text_character_size);
		units.setFillColor(sf::Color::Black);
		researchButton.setPosition(game_button_2_x, game_button_y);
		research.setPosition(game_button_2_x + research_x_offset, game_button_text_y);
		research.setCharacterSize(text_character_size);
		research.setFillColor(sf::Color::Black);
		fleetButton.setPosition(game_button_3_x, game_button_y);
		fleet.setPosition(game_button_3_x + fleet_x_offset, game_button_text_y);
		fleet.setCharacterSize(text_character_size);
		fleet.setFillColor(sf::Color::Black);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMap.setPosition(game_button_4_x + worldmap_x_offset, game_button_text_y);
		worldMap.setCharacterSize(text_character_size);
		worldMap.setFillColor(sf::Color::Black);
	}
	GameEvent Dashboard::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (unitsButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToUnits;
		}
		else if (researchButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToResearch;
		}
		else if (fleetButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToFleet;
		}
		else if (worldMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

		return gameEvent;
	}
	void Dashboard::update()
	{
		checkMouseOver(unitsButton);
		checkMouseOver(researchButton);
		checkMouseOver(fleetButton);
		checkMouseOver(worldMapButton);
	}
	void Dashboard::draw()
	{
		window.draw(unitsButton);
		window.draw(units);
		window.draw(researchButton);
		window.draw(research);
		window.draw(fleetButton);
		window.draw(fleet);
		window.draw(worldMapButton);
		window.draw(worldMap);
	}
}