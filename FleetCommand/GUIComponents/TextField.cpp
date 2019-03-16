#include "TextField.h"

namespace fleet {

	/*
	There is a good bit of implicit default initialization beside default parameters passed through constructor.
	The origin is treated as 0, 0. The text area has a default size of 70, 34.
	The default outline color is black with a thickness of 1.
	The text has a color of black and no outline.
	*/
	TextField::TextField(const std::string& newLabel, sf::Color background)
	{
		setPosition(0, 0);
		label.setString(newLabel);
		textField.setFillColor(background);
		textField.setOutlineColor(sf::Color::Black);
		textField.setOutlineThickness(textfield_default_thickness);
		fieldText.setString("");
	}

	void TextField::setPosition(float x, float y)
	{
		label.setPosition(x, y);
		textField.setPosition(x + xOffset, y);
		fieldText.setPosition(x + xOffset + field_text_offset, y + field_text_offset);
	}
	void TextField::setPosition(const sf::Vector2f& position)
	{
		setPosition(position.x, position.y);
	}
	void TextField::setDefaultDistance(float x_offset)
	{
		xOffset = x_offset;
	}

	void TextField::setSize(const sf::Vector2f& size)
	{
		textField.setSize(size);
	}
	void TextField::setFillColor(const sf::Color& color)
	{
		textField.setFillColor(color);
	}
	void TextField::setOutlineColor(const sf::Color& color)
	{
		textField.setOutlineColor(color);
	}
	void TextField::setOutlineThickness(float thickness)
	{
		textField.setOutlineThickness(thickness);
	}

	void TextField::setFont(const sf::Font& font)
	{
		label.setFont(font);
		fieldText.setFont(font);
	}
	void TextField::setLabelString(const std::string& string)
	{
		label.setString(string);
	}
	void TextField::setFieldString(const std::string& string)
	{
		fieldText.setString(string);
	}
	void TextField::setCharacterSize(unsigned size)
	{
		label.setCharacterSize(size);
		fieldText.setCharacterSize(size);
	}
	void TextField::setTextFillColor(const sf::Color& color)
	{
		label.setFillColor(color);
		fieldText.setFillColor(color);
	}
	void TextField::setTextOutlineColor(const sf::Color& color)
	{
		label.setOutlineColor(color);
		fieldText.setOutlineColor(color);
	}
	void TextField::setTextOutlineThickness(float thickness)
	{
		label.setOutlineThickness(thickness);
		fieldText.setOutlineThickness(thickness);
	}

	void TextField::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(label, states);
		target.draw(textField, states);
		target.draw(fieldText, states);
	}
}