#pragma once

#include <SFML\Graphics.hpp>

#include <string>

namespace fleet {

	constexpr float textfield_default_x_offset = 60.F;
	constexpr float field_text_offset = 2.F;
	constexpr float textfield_default_width = 70.F;
	constexpr float textfield_default_height = 34.F;
	constexpr float textfield_default_thickness = 1.F;

	/*
	Class to provide a Label and an editable text field for user input.
	*/
	class TextField : public sf::Drawable {
	public:
		TextField(const std::string& newLabel = "", sf::Color background = sf::Color::White);

		/*
		Position will define the x,y coordinate of the upper left corner of the label.
		The Rectangle will then be positioned by the default distance from the label unless otherwise specified.
		There is no y_offset. It cannot be altered at this time.
		*/
		void setPosition(float x, float y);
		void setPosition(const sf::Vector2f& position);
		void setDefaultDistance(float x_offset);

		/*
		Interface to effect changes to the User input box.
		*/
		void setSize(const sf::Vector2f& size);
		void setFillColor(const sf::Color& color);
		void setOutlineColor(const sf::Color& color);
		void setOutlineThickness(float thickness);

		/*
		Interface to effect changes to the text. This will effect both the label and field text.
		*/
		void setFont(const sf::Font& font);
		void setLabelString(const std::string& string);
		void setFieldString(const std::string& string);
		void setCharacterSize(unsigned size);
		void setTextFillColor(const sf::Color& color);
		void setTextOutlineColor(const sf::Color& color);
		void setTextOutlineThickness(float thickness);
	private:
		sf::Text label;
		sf::RectangleShape textField{ sf::Vector2f(textfield_default_width, textfield_default_height) };
		sf::Text fieldText;
		float xOffset{ textfield_default_x_offset };

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}