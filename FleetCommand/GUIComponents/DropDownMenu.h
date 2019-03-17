#pragma once

#include "GameEvent.h"

#include <SFML\Graphics.hpp>

namespace fleet {

	constexpr float drop_button_width = 200.F;
	constexpr float drop_button_height = 80.F;
	constexpr float drop_menu_text_y_offset = 10.F;
	constexpr float drop_menu_x = 0.F;
	constexpr float drop_menu_y = 0.F;
	constexpr float save_y = drop_menu_y + drop_button_height;
	constexpr float exit_y = save_y + drop_button_height;
	constexpr float drop_menu_text_x = drop_menu_x + 50.F;
	constexpr float menu_text_y = drop_menu_y + drop_menu_text_y_offset;
	constexpr float save_text_y = save_y + drop_menu_text_y_offset;
	constexpr float exit_text_y = exit_y + drop_menu_text_y_offset;

	class DropDownMenu : public sf::Drawable {
	public:
		explicit DropDownMenu(const sf::Font& font);

		GameEvent input(const sf::Vector2f& mousePos);
		void update(const sf::Vector2f& mousePos);
		void draw(sf::RenderWindow& window);
	private:
		const sf::Font& font;
		sf::RectangleShape menuButton{ sf::Vector2f(drop_button_width, drop_button_height) };
		sf::Text menu{ "Menu", font };
		sf::RectangleShape saveButton{ sf::Vector2f(drop_button_width, drop_button_height) };
		sf::Text save{ "Save", font };
		sf::RectangleShape exitButton{ sf::Vector2f(drop_button_width, drop_button_height) };
		sf::Text exit{ "Exit", font };
		bool menuOpen{ false };

		void mouseOverButtons(const sf::Vector2f& mousePos);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}