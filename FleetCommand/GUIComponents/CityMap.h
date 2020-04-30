#pragma once

#include "IMap.h"

namespace fleet {
	class CityMap : public IMap {
	public:
		void setCity(const std::string& name);

		void setPosition(float x, float y) { origin = sf::Vector2f(x, y); }

		GameEvent input(const sf::Vector2f& mousePos) override;
		void update(const sf::Vector2f& mousePos) override;
	private:
		sf::Texture spriteSheet;
		std::vector<unsigned> tileValues;
		std::vector<sf::RectangleShape> tileMap;
		std::string cityName{ "un-initialized" };
		bool draggable{ true };
		std::string citySize = "small"; //TODO: Needs to be initialized dynamically.
		sf::Vector2f origin;

		void createTileMap();
		void setTileColor(sf::RectangleShape& tile, unsigned value);
		void setTilePosition(sf::RectangleShape& tile, unsigned index, float tileWidth);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}