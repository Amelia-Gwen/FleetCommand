#include "gtest/gtest.h"

#include "UpgradeButton.h"

#include <Graphics.hpp>

namespace fleet {
	class UpgradeButtonTest : public testing::Test {
	protected:
		sf::Font font;
		UpgradeButton button{ "Test Button", sf::Font(), 5 };
	};

	TEST_F(UpgradeButtonTest, setPosition) {
		sf::Vector2f position{ 0.F, 0.F };
		button.setPosition(position);
		ASSERT_FLOAT_EQ(position.x, button.getPosition().x);
		ASSERT_FLOAT_EQ(position.y, button.getPosition().y);
		button.setPosition(0.F, 0.F);
		ASSERT_FLOAT_EQ(position.x, button.getPosition().x);
		ASSERT_FLOAT_EQ(position.y, button.getPosition().y);
		button.setPosition(sf::Vector2f());
		ASSERT_FLOAT_EQ(position.x, button.getPosition().x);
		ASSERT_FLOAT_EQ(position.y, button.getPosition().y);
		button.setPosition(200.F, 200.F);
		ASSERT_NE(position.x, button.getPosition().x);
		ASSERT_NE(position.y, button.getPosition().y);
	}

	TEST_F(UpgradeButtonTest, setLabelString) {
		std::string test_string{ "Test Pass" };
		ASSERT_STREQ("Test Button", button.getLabelString().toAnsiString().c_str()) << "Not named Test Button";
		button.setLabelString(test_string);
		ASSERT_STREQ("Test Pass", button.getLabelString().toAnsiString().c_str()) << test_string << " not assigned properly";
		ASSERT_STREQ(test_string.c_str(), button.getLabelString().toAnsiString().c_str()) << test_string << " not assigned properly pt2";
		button.setLabelString("");
		ASSERT_STREQ("",button.getLabelString().toAnsiString().c_str()) << "Breaking on empty string";
		ASSERT_STRNE(test_string.c_str(), button.getLabelString().toAnsiString().c_str()) << "Breaking on inequality test";
	}

	TEST_F(UpgradeButtonTest, setCharacterSize) {
		unsigned test_size{ 52 };
		ASSERT_EQ(30, button.getCharacterSize());
		ASSERT_NE(test_size, button.getCharacterSize());
		button.setCharacterSize(test_size);
		ASSERT_EQ(52, button.getCharacterSize());
	}

	TEST_F(UpgradeButtonTest, setTextFillColor) {
		sf::Color color{ sf::Color::Green };
		ASSERT_NE(color, button.getTextFillColor());
		ASSERT_EQ(sf::Color::White, button.getTextFillColor());
		button.setTextFillColor(color);
		ASSERT_EQ(sf::Color::Green, button.getTextFillColor());
		button.setTextFillColor(sf::Color());
		ASSERT_EQ(sf::Color::Black, button.getTextFillColor());
	}

	TEST_F(UpgradeButtonTest, input) {
		ASSERT_TRUE(button.input(sf::Vector2f(), true));
		ASSERT_FALSE(button.input(sf::Vector2f(), false));
		ASSERT_FALSE(button.input(sf::Vector2f(500.F, 900.F), true));
	}
}