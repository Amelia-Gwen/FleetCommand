#pragma once

#include "IScreen.h"

#include "DisplayPanel.h"
#include "GUIButton.h"
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
		GUIButton dashButton{ sf::Vector2f(game_button_width, game_button_height), "Dashboard", font };
		GUIButton researchButton{ sf::Vector2f(game_button_width, game_button_height), "Research", font };
		GUIButton fleetButton{ sf::Vector2f(game_button_width, game_button_height), "Fleet", font };
		GUIButton endTurnButton{ sf::Vector2f(game_button_width, game_button_height), "End Turn", font };
	};
}