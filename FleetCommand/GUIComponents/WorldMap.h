#pragma once

#include "IMap.h"
#include "Model.h"

namespace fleet {
	class WorldMap : public IMap {
	public:
		explicit WorldMap(const Model& model, const sf::Font& font);

		GameEvent input(const sf::Vector2f& mousePos) override;
	private:
		const Model& model;
		const sf::Font& font;
		std::vector<std::pair<sf::RectangleShape, sf::Text>> cities;
		int cityIndex{ 0 };

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}