#include "UnitButton.h"

namespace fleet {
	UnitButton::UnitButton(const std::string& newLabel, const sf::Font& font, unsigned baseCost) :
		label{ newLabel, font },
		baseCost{ baseCost },
		baseCostLabel{ std::to_string(baseCost), font }
	{
	}

	void UnitButton::setPosition(float x, float y)
	{
		button.setPosition(x, y);
		label.setPosition(x, y + default_unit_button_height);
		baseCostLabel.setPosition(x, default_cost_y_offset);
	}
	void UnitButton::setPosition(const sf::Vector2f& position)
	{
		setPosition(position.x, position.y);
	}
	bool UnitButton::input(const sf::Vector2f& mousePos, bool canAfford)
	{
		return canAfford && button.getGlobalBounds().contains(mousePos);
	}
	void UnitButton::update(const sf::Vector2f& mousePos, bool canAfford)
	{
		if (canAfford && button.getGlobalBounds().contains(mousePos)) {
			button.setFillColor(sf::Color::Green);
		}
		else {
			button.setFillColor(sf::Color::Cyan);
		}
	}

	void UnitButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(button, states);
		target.draw(label, states);
		target.draw(baseCostLabel, states);
	}
}