#include "UnitButton.h"

#include "Evaluations.h"

namespace fleet {
	UnitButton::UnitButton(const std::string& newLabel, const sf::Font& font, unsigned baseCost) :
		label{ font, newLabel },
		cost{ baseCost },
		CostLabel{ font, "$" + std::to_string(baseCost)}
	{
		CostLabel.setFillColor(sf::Color::Yellow);
	}

	void UnitButton::setPosition(float x, float y)
	{
		button.setPosition(sf::Vector2f(x, y));
		label.setPosition(sf::Vector2f(x, y + default_unit_button_height));
		CostLabel.setPosition(sf::Vector2f(x, y));
	}
	void UnitButton::setPosition(const sf::Vector2f& position)
	{
		setPosition(position.x, position.y);
	}
	bool UnitButton::input(const sf::Vector2f& mousePos, unsigned cash)
	{
		return canAfford(cost, cash) && button.getGlobalBounds().contains(mousePos);
	}
	void UnitButton::update(const sf::Vector2f& mousePos, unsigned cash)
	{
		if (canAfford(cost, cash) && button.getGlobalBounds().contains(mousePos)) {
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
		target.draw(CostLabel, states);
	}
}