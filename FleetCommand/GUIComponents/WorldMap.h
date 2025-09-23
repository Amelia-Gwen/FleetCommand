#pragma once

#include "IMap.h"
#include "Model.h"

namespace fleet {
	class WorldMap : public IMap {
	public:
		explicit WorldMap(const Model& model, const sf::Font& font);

		unsigned activeCity() const { return cityIndex; }

		GameEvent input(const sf::Vector2f& mousePos) override;
		void update(const sf::Vector2f& mousePos) override;
	private:
		const Model& model;
		std::vector<std::pair<sf::RectangleShape, sf::Text>> cities;
		unsigned cityIndex{ 0 };

		void checkMouseOver(sf::RectangleShape& button, sf::Vector2f mousePos);
		void repositionCities();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}