#pragma once

#include "GameEvent.h"
#include "Expressions.h"

#include <Graphics.hpp>

namespace fleet {
	class IMap : public sf::Drawable {
	public:
		IMap();
		virtual ~IMap() = default;

		void releaseGrip() { grabbed = false; }
		void setPosition(float x, float y);

		virtual GameEvent input(const sf::Vector2f& mousePos) = 0;
		virtual void update(const sf::Vector2f& mousePos) = 0;
	protected:
		sf::Texture worldMap;
		sf::RectangleShape map{ sf::Vector2f(map_width, map_height) };
		sf::RectangleShape zoomIn{ sf::Vector2f(map_button_side, map_button_side) };
		sf::RectangleShape zoomOut{ sf::Vector2f(map_button_side, map_button_side) };
		float mapX{ 0.F };
		float mapY{ 0.F };
		unsigned mapScale{ minimum_scale };
		sf::Vector2f mouseWasAt{ 0.F, 0.F };
		bool grabbed{ false };

		void grab(const sf::Vector2f& mousePos);
		void resizeMap();
		void moveMap(const sf::Vector2f& newPos);
		void constrainMapCoordinates(float& x, float& y);
		void mouseOverButtons(const sf::Vector2f& mousePos);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	};
}