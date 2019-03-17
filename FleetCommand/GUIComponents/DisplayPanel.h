#pragma once

#include "Model.h"
#include "DropDownMenu.h"

#include <SFML\Graphics.hpp>

namespace fleet {

	constexpr float panel_x_offset = drop_button_width;
	constexpr float panel_width = screen_width_float - panel_x_offset;
	constexpr float panel_box_width = panel_width / 4.F;
	constexpr float panel_box_height = drop_button_height;
	constexpr float panel_1_x = panel_x_offset;
	constexpr float panel_2_x = panel_1_x + panel_box_width;
	constexpr float panel_3_x = panel_2_x + panel_box_width;
	constexpr float panel_4_x = panel_3_x + panel_box_width;
	constexpr float panel_y = 0.F;
	constexpr float name_x_offset = 15.F;
	constexpr float panel_text_x_offset = 80.F;
	constexpr float panel_text_y_offset = 15.F;
	constexpr float name_x = panel_1_x + name_x_offset;
	constexpr float cash_x = panel_2_x + panel_text_x_offset;
	constexpr float oil_x = panel_3_x + panel_text_x_offset;
	constexpr float research_x = panel_4_x + panel_text_x_offset;
	constexpr float panel_text_y = panel_y + panel_text_y_offset;

	class DisplayPanel {
	public:
		explicit DisplayPanel(const Model& model, const sf::Font& font);

		GameEvent input(const sf::Vector2f& mousePos);
		void update(const sf::Vector2f& mousePos);
		void draw(sf::RenderWindow& window);
	private:
		const Model& model;
		const sf::Font& font;
		DropDownMenu dropDownMenu{ font };

		sf::RectangleShape nameBox{ sf::Vector2f{panel_box_width, panel_box_height} };
		sf::Text name{ "un-initialized", font };
		sf::RectangleShape cashBox{ sf::Vector2f{panel_box_width, panel_box_height} };
		sf::Text cash{ "un-initialized", font };
		sf::RectangleShape oilBox{ sf::Vector2f{panel_box_width, panel_box_height} };
		sf::Text oil{ "un-initialized", font };
		sf::RectangleShape researchBox{ sf::Vector2f{panel_box_width, panel_box_height} };
		sf::Text research{ "un-initialized", font };
	};
}