#include "DropBox.h"

namespace fleet {
	/*
	Default initialization includes. 0, 0 as origin point. White as default background color.
	Default thickness of 1. The default number of elements is zero. The user must explicitly create each element.
	*/
	DropBox::DropBox(const std::string& newLabel)
	{
		setPosition(0, 0);
		label.setString(newLabel);
	}

	void DropBox::setPosition(float x, float y)
	{
		label.setPosition(x, y);
		for (unsigned i = 0; i < elements.size(); ++i) {
			unsigned position = i - selectedIndex;
			float yOffset = box_default_height * position;
			elements[i].second.setPosition(x + xOffset, y + yOffset);
			elements[i].first.setPosition(x + xOffset + box_text_offset, y + yOffset + box_text_offset);
		}
	}
	void DropBox::setPosition(const sf::Vector2f& position)
	{
		setPosition(position.x, position.y);
	}
	void DropBox::setDefaultDistance(float x_offset)
	{
		xOffset = x_offset;
	}

	void DropBox::setFillColor(const sf::Color& color)
	{
		for (auto& element : elements) {
			element.second.setFillColor(color);
		}
	}
	void DropBox::setOutlineColor(const sf::Color& color)
	{
		for (auto& element : elements) {
			element.second.setOutlineColor(color);
		}
	}
	void DropBox::setOutlineThickness(float thickness)
	{
		for (auto& element : elements) {
			element.second.setOutlineThickness(thickness);
		}
	}

	void DropBox::setFont(const sf::Font& font)
	{
		label.setFont(font);
		for (auto& element : elements) {
			element.first.setFont(font);
		}
	}
	void DropBox::setLabelString(const std::string& string)
	{
		label.setString(string);
	}
	void DropBox::setCharacterSize(unsigned newSize)
	{
		label.setCharacterSize(newSize);
		for (auto& element : elements) {
			element.first.setCharacterSize(newSize);
		}
	}
	void DropBox::setTextFillColor(const sf::Color& color)
	{
		label.setFillColor(color);
		for (auto& element : elements) {
			element.first.setFillColor(color);
		}
	}
	void DropBox::setTextOutlineColor(const sf::Color& color)
	{
		for (auto& element : elements) {
			element.first.setOutlineColor(color);
		}
	}
	void DropBox::setTextOutlineThickness(float thickness)
	{
		for (auto& element : elements) {
			element.first.setOutlineThickness(thickness);
		}
	}

	void DropBox::addElement(const std::string& string, const sf::Font& font)
	{
		elements.emplace_back(std::make_pair<sf::Text, sf::RectangleShape>(
			sf::Text(string, font), sf::RectangleShape(sf::Vector2f(box_default_width, box_default_height))
			));
		int distance = size - selectedIndex;
		float x = label.getPosition().x + xOffset;
		float y = label.getPosition().y + (distance * box_default_height);
		elements[size].second.setPosition(x, y);
		elements[size].first.setPosition(x + box_text_offset, y + box_text_offset);
		elements[size].first.setFillColor(sf::Color::Black);
		++size;
	}
	void DropBox::setElement(const std::string& string, unsigned index)
	{
		elements[index].first.setString(string);
	}
	void DropBox::setDefaultElement(unsigned index)
	{
		selectedIndex = index;
		setPosition(label.getPosition());
	}

	std::string DropBox::getValue() const
	{
		return elements[selectedIndex].first.getString();
	}

	void DropBox::input(const sf::Vector2f& mousePos)
	{
		if (open) {
			for (unsigned i = 0; i < elements.size(); ++i) {
				if (elements[i].second.getGlobalBounds().contains(mousePos)) {
					sf::Vector2f position = label.getPosition();
					selectedIndex = i;
					setPosition(position);
					break;
				}
			}
			open = false;
		}
		else {
			if (elements[selectedIndex].second.getGlobalBounds().contains(mousePos)) {
				open = true;
			}
		}
	}

	void DropBox::update(const sf::Vector2f& mousePos)
	{
		for (auto& elem : elements) {
			if (elem.second.getGlobalBounds().contains(mousePos)) {
				elem.second.setFillColor(sf::Color::Cyan);
			}
			else {
				elem.second.setFillColor(sf::Color::White);
			}
		}
	}

	void DropBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(label, states);
		if (open) {
			for (auto& element : elements) {
				target.draw(element.second, states);
				target.draw(element.first, states);
			}
		}
		else {
			target.draw(elements[selectedIndex].second, states);
			target.draw(elements[selectedIndex].first, states);
		}
	}
}