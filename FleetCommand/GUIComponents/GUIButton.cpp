#include "GUIButton.h"

#include "Expressions.h"

namespace fleet {
	GUIButton::GUIButton(const sf::Vector2f& size, const std::string& newLabel, const sf::Font& font) :
		button{ size },
		label{ font, newLabel }
	{
		button.setFillColor(sf::Color::Cyan);
		label.setFillColor(sf::Color::Black);
	}

	void GUIButton::setPosition(float x, float y)
	{
		button.setPosition(sf::Vector2f(x, y));
		label.setPosition(sf::Vector2f(x + labelOffset.x, y + labelOffset.y));
	}
	void GUIButton::setLabelOffset(const sf::Vector2f& offset)
	{
		labelOffset = offset;
		label.setPosition(sf::Vector2f(button.getPosition().x + labelOffset.x, button.getPosition().y + labelOffset.y));
	}
	void GUIButton::setCharacterSize(unsigned newSize)
	{
		label.setCharacterSize(newSize);
	}
	void GUIButton::setLabel(const std::string& newLabel)
	{
		label.setString(newLabel);
	}
	void GUIButton::setActive(bool isActive)
	{
		active = isActive;
	}

	bool GUIButton::input(const sf::Vector2f& mousePos)
	{
		return active && button.getGlobalBounds().contains(mousePos);
	}
	void GUIButton::update(const sf::Vector2f& mousePos)
	{
		if (active && button.getGlobalBounds().contains(mousePos)) {
			button.setFillColor(sf::Color::Green);
		}
		else {
			button.setFillColor(sf::Color::Cyan);
		}
	}

	void GUIButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(button, states);
		target.draw(label, states);
	}
}