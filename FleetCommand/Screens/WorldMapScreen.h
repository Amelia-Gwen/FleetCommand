#pragma once

#include "IScreen.h"
#include "DisplayPanel.h"
#include "Expressions.h"
#include "WorldMap.h"

namespace fleet {

	constexpr float world_x_offset = 60.F;
	constexpr float world_dash_x = game_button_1_x + world_x_offset;
	constexpr float world_research_x = game_button_2_x + world_x_offset;
	constexpr float world_fleet_x = game_button_3_x + world_x_offset + 40.F;
	constexpr float world_endturn_x = game_button_4_x + world_x_offset;
	constexpr float world_map_city_width = 10.F;
	constexpr float world_map_city_height = 10.F;

	class WorldMapScreen : public IScreen {
	public:
		explicit WorldMapScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel);

		void releaseGrip() { worldMap.releaseGrip(); }

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