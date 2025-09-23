#include "WorldMapScreen.h"

namespace fleet {
	WorldMapScreen::WorldMapScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		worldMap.setPosition(0.F, panel_box_height);
		dashButton.setLabelOffset(sf::Vector2f(dashboard_x_offset, game_text_y_offset));
		dashButton.setPosition(game_button_1_x, game_button_y);
		dashButton.setCharacterSize(text_character_size);
		researchButton.setLabelOffset(sf::Vector2f(research_x_offset, game_text_y_offset));
		researchButton.setPosition(game_button_2_x, game_button_y);
		researchButton.setCharacterSize(text_character_size);
		fleetButton.setLabelOffset(sf::Vector2f(fleet_x_offset, game_text_y_offset));
		fleetButton.setPosition(game_button_3_x, game_button_y);
		fleetButton.setCharacterSize(text_character_size);
		endTurnButton.setLabelOffset(sf::Vector2f(endturn_x_offset, game_text_y_offset));
		endTurnButton.setPosition(game_button_4_x, game_button_y);
		endTurnButton.setCharacterSize(text_character_size);
	}
	GameEvent WorldMapScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashButton.input(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (researchButton.input(mousePos)) {
			return GameEvent::GoToResearch;
		}
		else if (fleetButton.input(mousePos)) {
			return GameEvent::GoToFleet;
		}
		else if (endTurnButton.input(mousePos)) {
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

		dashButton.update(mousePos);
		researchButton.update(mousePos);
		fleetButton.update(mousePos);
		endTurnButton.update(mousePos);
	}
	void WorldMapScreen::draw()
	{
		window.draw(worldMap);
		window.draw(displayPanel);
		window.draw(dashButton);
		window.draw(researchButton);
		window.draw(fleetButton);
		window.draw(endTurnButton);
	}
}