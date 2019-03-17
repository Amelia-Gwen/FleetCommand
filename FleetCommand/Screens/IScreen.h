#pragma once

#include "GameEvent.h"

#include <SFML\Graphics.hpp>

namespace fleet {

	constexpr unsigned text_character_size = 45U;
	constexpr float menu_back_button_width = 100.F;
	constexpr float menu_back_button_height = 50.F;
	constexpr float menu_back_x = 0.F;
	constexpr float menu_back_y = 0.F;

	/*
	Interface class for all screens.
	Constructor takes a reference to the window that will draw the screen as well as contain mouse coordinates
	and a reference to the font that will be used for all text.
	input() returns a GameEvent based on user interaction with the screen. default return will be GameEvent::None.
	update() will simply progress the screen one frame.
	draw() will have the window render the appropriate elements.
	*/
	class IScreen {
	public:
		explicit IScreen(sf::RenderWindow& window, const sf::Font& font);
		virtual ~IScreen() = default;

		virtual GameEvent input() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
	protected:
		sf::RenderWindow& window;
		const sf::Font& font;

		void checkMouseOver(sf::RectangleShape& button);
	};
}