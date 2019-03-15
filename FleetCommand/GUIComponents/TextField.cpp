#include "TextField.h"

namespace fleet {
	TextField::TextField(const std::string& newLabel, sf::Color background)
	{
		label.setString(newLabel);
		textField.setFillColor(background);
	}
}