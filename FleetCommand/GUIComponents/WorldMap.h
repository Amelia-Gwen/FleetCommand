#pragma once

#include "IMap.h"
#include "Model.h"

namespace fleet {

	constexpr float world_x_offset = 60.F;
	constexpr float world_dash_x = game_button_1_x + world_x_offset;
	constexpr float world_research_x = game_button_2_x + world_x_offset;
	constexpr float world_fleet_x = game_button_3_x + world_x_offset + 40.F;
	constexpr float world_endturn_x = game_button_4_x + world_x_offset;
	constexpr float world_map_city_width = 10.F;
	constexpr float world_map_city_height = 10.F;

	class WorldMap : public IMap {
	public:
		explicit WorldMap(const Model& model, const sf::Font& font);

		GameEvent input(const sf::Vector2f& mousePos) override;
		void update(const sf::Vector2f& mousePos) override;
	private:
		const Model& model;
		const sf::Font& font;
		std::vector<std::pair<sf::RectangleShape, sf::Text>> cities;
		int cityIndex{ 0 };

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}