#pragma once

#include "IScreen.h"
#include "DisplayPanel.h"
#include "WorldMap.h"

namespace fleet {
	class WorldMapScreen : public IScreen {
	public:
		explicit WorldMapScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel);

		void releaseGrip() { worldMap.releaseGrip(); }
		unsigned activeCity() const { return worldMap.activeCity(); }

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		const Model& model;
		DisplayPanel& displayPanel;		
		WorldMap worldMap{ model, font };
		sf::RectangleShape dashButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text dashboard{ "Dashboard", font };
		sf::RectangleShape researchButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text research{ "Research", font };
		sf::RectangleShape fleetButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text fleet{ "Fleet", font };
		sf::RectangleShape endTurnButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text endTurn{ "End Turn", font };
	};
}