#include "UpgradeButton.h"

namespace fleet {
	UpgradeButton::UpgradeButton(std::string& newLabel, unsigned numUpgrades)
	{
		label.setString(newLabel);
		float indicatorWidth = default_upgrade_width / numUpgrades;
		for (unsigned i = 0; i < numUpgrades; ++i) {
			indicators.emplace_back(sf::RectangleShape(sf::Vector2f(indicatorWidth, default_indicator_height)));
		}

		button.setFillColor(sf::Color::Cyan);
		button.setOutlineThickness(upgrade_button_outline);
		for (auto& indicator : indicators) {
			indicator.setFillColor(sf::Color::Cyan);
			indicator.setOutlineThickness(upgrade_button_outline);
		}
	}

	void UpgradeButton::setPosition(float x, float y)
	{
		button.setPosition(x, y);
		float indicatorX = x;
		float indicatorY = y + (default_upgrade_height - default_indicator_height);
		for (auto& indicator : indicators) {
			indicator.setPosition(indicatorX, indicatorY);
			indicatorX += indicator.getSize().x;
		}
		float labelY = y + default_upgrade_height + upgrade_label_y_offset;
		label.setPosition(x, labelY);
	}
	void UpgradeButton::setPosition(const sf::Vector2f& position)
	{
		setPosition(position.x, position.y);
	}
	void UpgradeButton::setFont(const sf::Font& font)
	{
		label.setFont(font);
	}
	void UpgradeButton::setLabelString(const std::string& string)
	{
		label.setString(string);
	}
	void UpgradeButton::setCharacterSize(unsigned newSize)
	{
		label.setCharacterSize(newSize);
	}
	void UpgradeButton::setTextFillColor(const sf::Color& color)
	{
		label.setFillColor(color);
	}
	void UpgradeButton::setTextOutlineColor(const sf::Color& color)
	{
		label.setOutlineColor(color);
	}
	void UpgradeButton::setTextOutlineThickness(float thickness)
	{
		label.setOutlineThickness(thickness);
	}

	void UpgradeButton::input(const sf::Vector2f& mousePos)
	{
		if (button.getGlobalBounds().contains(mousePos)) {
			// increment value by one.
		}
	}
	void UpgradeButton::update(const sf::Vector2f& mousePos)
	{
		// add check that upgrade requirements are met.
		if (button.getGlobalBounds().contains(mousePos)) {
			button.setFillColor(sf::Color::Green);
		}
		else {
			button.setFillColor(sf::Color::Cyan);
		}
	}

	void UpgradeButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(button, states);
		for (auto& indicator : indicators) {
			target.draw(indicator, states);
		}
		target.draw(label, states);
	}
}