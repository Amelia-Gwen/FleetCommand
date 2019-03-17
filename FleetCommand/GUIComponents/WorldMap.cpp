#include "WorldMap.h"

#include <cstddef>

namespace fleet {
	WorldMap::WorldMap(const Model& model, const sf::Font& font) :
		model{ model },
		font{ font }
	{
		std::size_t counter = 0;
		for (const auto& city : model.cityList()) {
			cities.emplace_back(std::make_pair(
				sf::RectangleShape(sf::Vector2f(world_map_city_width, world_map_city_height)), sf::Text(city.cityName(), font)
			));
			float position_x = city_position_multiplier_x * city.location().x;
			float position_y = city_position_multiplier_y * city.location().y;
			cities[counter].first.setPosition(position_x, position_y);
			position_x += city_text_offset_x;
			position_y += city_text_offset_y;
			cities[counter].second.setCharacterSize(city_name_text_size);
			cities[counter].second.setFillColor(sf::Color::Black);
			cities[counter].second.setPosition(position_x, position_y);
			++counter;
		}
		// set cities
	}
	GameEvent WorldMap::input(const sf::Vector2f& mousePos)
	{
		for (std::size_t i = 0; i < cities.size(); ++i) {
			if (cities[i].first.getGlobalBounds().contains(mousePos)) {
				cityIndex = i;
				return GameEvent::OpenCity;
			}
		}

		if (zoomIn.getGlobalBounds().contains(mousePos) && mapScale < maximum_scale) {
			++mapScale;
			resizeMap();
			return GameEvent::ActionComplete;
		}
		else if (center.getGlobalBounds().contains(mousePos)) {
			// focus on selected city
			// if no city selected focus on 0,0 center point.
			// do not exceed constraints. map edges must never exist within the bounds of the frame.
		}
		else if (zoomOut.getGlobalBounds().contains(mousePos) && mapScale > minimum_scale) {
			--mapScale;
			resizeMap();
			return GameEvent::ActionComplete;
		}
		else if (map.getGlobalBounds().contains(mousePos)) {
			grab(mousePos);
		}

		return GameEvent::None;
	}
	void WorldMap::update(const sf::Vector2f& mousePos)
	{
		mouseOverButtons(mousePos);
		moveMap(mousePos);
	}
	void WorldMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(map, states);
		for (auto& city : cities)
		{
			target.draw(city.first, states);
			target.draw(city.second, states);
		}
		target.draw(zoomIn, states);
		target.draw(center, states);
		target.draw(zoomOut, states);
	}
}