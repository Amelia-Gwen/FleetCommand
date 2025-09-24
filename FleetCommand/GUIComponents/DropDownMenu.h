#pragma once

#include "GameEvent.h"
#include "Expressions.h"

#include <Graphics.hpp>

namespace fleet {
	class DropDownMenu : public sf::Drawable {
	public:
		explicit DropDownMenu(const sf::Font& font);

		GameEvent input(const sf::Vector2f& mousePos);
		void update(const sf::Vector2f& mousePos);
	private:
		const sf::Font& font;
		sf::RectangleShape menuButton{ sf::Vector2f(drop_button_width, drop_button_height) };
		sf::Text menu{ font, "Menu" };
		sf::RectangleShape saveButton{ sf::Vector2f(drop_button_width, drop_button_height) };
		sf::Text save{ font, "Save" };
		sf::RectangleShape exitButton{ sf::Vector2f(drop_button_width, drop_button_height) };
		sf::Text exit{ font, "Exit" };
		bool menuOpen{ false };

		void mouseOverButtons(const sf::Vector2f& mousePos);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}