#pragma once

#include "Model.h"
#include "DropDownMenu.h"
#include "Expressions.h"

#include <Graphics.hpp>

namespace fleet {
	class DisplayPanel : public sf::Drawable {
	public:
		explicit DisplayPanel(const Model& model, const sf::Font& font);

		GameEvent input(const sf::Vector2f& mousePos);
		void update(const sf::Vector2f& mousePos);
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

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}