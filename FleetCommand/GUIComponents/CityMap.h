#pragma once

#include "IMap.h"

namespace fleet {
	class CityMap : public IMap {
	public:
		CityMap();

		void setCity(const std::string& name); // pass 2d matix of tileMap?

		GameEvent input(const sf::Vector2f& mousePos) override;
	private:
		sf::Texture spriteSheet{};
		std::vector<std::vector<sf::Sprite>> cityMap{};
		std::string cityName{ "Andwar" };
		bool draggable{ true };

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}