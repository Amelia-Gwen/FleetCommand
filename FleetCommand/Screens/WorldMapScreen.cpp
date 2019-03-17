#include "WorldMapScreen.h"

namespace fleet {
	WorldMapScreen::WorldMapScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		worldMap.setPosition(0.F, panel_box_height);
		dashButton.setPosition(game_button_1_x, game_button_y);
		dashboard.setPosition(world_dash_x, game_button_text_y);
		dashboard.setCharacterSize(text_character_size);
		dashboard.setFillColor(sf::Color::Black);
		researchButton.setPosition(game_button_2_x, game_button_y);
		research.setPosition(world_research_x, game_button_text_y);
		research.setCharacterSize(text_character_size);
		research.setFillColor(sf::Color::Black);
		fleetButton.setPosition(game_button_3_x, game_button_y);
		fleet.setPosition(world_fleet_x, game_button_text_y);
		fleet.setCharacterSize(text_character_size);
		fleet.setFillColor(sf::Color::Black);
		endTurnButton.setPosition(game_button_4_x, game_button_y);
		endTurn.setPosition(world_endturn_x, game_button_text_y);
		endTurn.setCharacterSize(text_character_size);
	    endTurn.setFillColor(sf::Color::Black);
	}
	GameEvent WorldMapScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (researchButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToResearch;
		}
		else if (fleetButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToFleet;
		}
		else if (endTurnButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::EndTurn;
		}
		if (gameEvent != GameEvent::None) { return gameEvent; }

		gameEvent = worldMap.input(mousePos);

		return gameEvent;
	}
	void WorldMapScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		worldMap.update(mousePos);
		displayPanel.update(mousePos);
		checkMouseOver(dashButton);
		checkMouseOver(researchButton);
		checkMouseOver(fleetButton);
		checkMouseOver(endTurnButton);
	}
	void WorldMapScreen::draw()
	{
		window.draw(worldMap);
		window.draw(displayPanel);
		window.draw(dashButton);
		window.draw(dashboard);
		window.draw(researchButton);
		window.draw(research);
		window.draw(fleetButton);
		window.draw(fleet);
		window.draw(endTurnButton);
		window.draw(endTurn);
	}
}