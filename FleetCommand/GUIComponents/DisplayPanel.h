#pragma once

#include "Model.h"
#include "DropDownMenu.h"

#include <SFML\Graphics.hpp>

namespace fleet {
	class DisplayPanel {
	public:
		DisplayPanel(const Model& model, const sf::Font& font);
	private:
		const Model& model;
		const sf::Font& font;
		DropDownMenu dropDownMenu;
	};
}