#include "WorldMap.h"

namespace fleet {
	WorldMap::WorldMap(const Model& model, const sf::Font& font) :
		model{ model }
	{
		unsigned counter = 0;
		for (const auto& city : model.cityList()) {
			cities.emplace_back(std::make_pair(
				sf::RectangleShape(sf::Vector2f(world_map_city_width, world_map_city_height)), sf::Text(city.cityName(), font)
			));
			float position_x = mapX + (city_position_multiplier_x * city.location().x);
			float position_y = mapY + (city_position_multiplier_y * city.location().y);
			cities[counter].first.setPosition(position_x, position_y);
			cities[counter].second.setCharacterSize(city_name_text_size);
			cities[counter].second.setFillColor(sf::Color::Black);
			cities[counter].second.setPosition(position_x + city_text_offset_x, position_y + city_text_offset_y);
			++counter;
		}
	}
	GameEvent WorldMap::input(const sf::Vector2f& mousePos)
	{
		for (unsigned i = 0; i < cities.size(); ++i) {
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
		for (auto& city : cities) {
			checkMouseOver(city.first, mousePos);
		}
		moveMap(mousePos);
		repositionCities();
	}

	void WorldMap::checkMouseOver(sf::RectangleShape& button, sf::Vector2f mousePos)
	{
		if (button.getGlobalBounds().contains(mousePos))
		{
			button.setFillColor(sf::Color::Green);
		}
		else
		{
			button.setFillColor(sf::Color::Cyan);
		}
	}

	void WorldMap::repositionCities()
	{
		// TODO: only perform when alterations are made.
		std::size_t index = 0;
		sf::Vector2f scale = map.getScale();
		for (const auto& city : model.cityList()) {
			float position_x = city_position_multiplier_x * city.location().x;
			float position_y = city_position_multiplier_y * city.location().y;
			position_x *= scale.x;
			position_y *= scale.y;
			position_x += map.getPosition().x;
			position_y += map.getPosition().y;
			cities[index].first.setPosition(position_x, position_y);
			cities[index].first.setScale(scale);
			cities[index].second.setPosition(position_x + city_text_offset_x, position_y + city_text_offset_y);
			++index;
		}
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
		target.draw(zoomOut, states);
	}
}