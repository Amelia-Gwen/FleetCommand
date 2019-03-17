#pragma once

#include "GameEvent.h"
#include "View.h"
#include "Expressions.h"

#include <SFML\Graphics.hpp>

namespace fleet {

	constexpr float map_width = screen_width_float;
	constexpr float map_height = screen_height_float - (drop_button_height + game_button_height);
	constexpr float map_button_side = 30.F;
	constexpr float map_button_y = 650.F;
	constexpr float zoom_in_x = 60.F;
	constexpr float center_x = 100.F;
	constexpr float zoom_out_x = 140.F;
	constexpr unsigned minimum_scale = 1;
	constexpr unsigned maximum_scale = 10;
	constexpr float city_position_multiplier_x = map_width / 25.F;
	constexpr float city_position_multiplier_y = map_height / 25.F;
	constexpr unsigned city_name_text_size = 10U;
	constexpr float city_text_offset_x = -15.F;
	constexpr float city_text_offset_y = 12.F;

	class IMap {
	public:
		IMap();
		virtual ~IMap() = default;

		void releaseGrip() { grabbed = false; }
		void setPosition(float x, float y);

		virtual GameEvent input(const sf::Vector2f& mousePos) = 0;
		virtual void update(const sf::Vector2f& mousePos) = 0;
		virtual void draw(sf::RenderWindow& window) = 0;
	protected:
		sf::Texture worldMap;
		sf::RectangleShape map{ sf::Vector2f(map_width, map_height) };
		sf::RectangleShape zoomIn{ sf::Vector2f(map_button_side, map_button_side) };
		sf::RectangleShape center{ sf::Vector2f(map_button_side, map_button_side) };
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
	};
}