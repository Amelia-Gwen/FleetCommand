#include "gtest/gtest.h"

#include "UpgradeButton.h"

#include "Exceptions.h"
#include "Expressions.h"

#include <Graphics.hpp>

namespace fleet {
	class UpgradeButtonTest : public testing::Test {
	public:
		void TearDown() override {
			if (button) {
				delete button;
			}
		}
	protected:
		UpgradeButton* button;
	};

	TEST_F(UpgradeButtonTest, constructor_accepts_empty_string) {
		button = new UpgradeButton("", sf::Font(), 5);
		ASSERT_STREQ("", button->getLabelString().toAnsiString().c_str());
	}

	TEST_F(UpgradeButtonTest, constructor_handles_large_strings) {
		std::string longString = "This is a very long string to test that the constructor of the \
			UpgradeButton class properly handles very long strings.";
		button = new UpgradeButton(longString, sf::Font(), 5);
		ASSERT_EQ(longString, button->getLabelString());
	}

	TEST_F(UpgradeButtonTest, constructor_fails_on_zero) {
		ASSERT_THROW(button = new UpgradeButton("Test String", sf::Font(), 0), DivideByZeroException);
	}

	TEST_F(UpgradeButtonTest, text_is_white_on_contruction) {
		button = new UpgradeButton("Test String", sf::Font(), 5);
		ASSERT_EQ(sf::Color::White, button->getTextFillColor());
	}

	TEST_F(UpgradeButtonTest, indicators_stacked_at_origin_point_on_construction) {
		button = new UpgradeButton("Test String", sf::Font(), 5);
		for (auto& indicator : button->getIndicators())
		{
			ASSERT_EQ(sf::Vector2f(), indicator.getPosition());
		}
	}

	TEST_F(UpgradeButtonTest, setPosition_sets_indicators_correctly) {
		unsigned short numIndicators = 5;
		button = new UpgradeButton("Test String", sf::Font(), numIndicators);
		sf::Vector2f position(5.F, 5.F);
		button->setPosition(position);
		float indicatorX = position.x;
		float indicatorY = position.y + (default_upgrade_height - default_indicator_height);
		for (auto& indicator : button->getIndicators()) {
			ASSERT_FLOAT_EQ(indicatorX, indicator.getPosition().x);
			ASSERT_FLOAT_EQ(indicatorY, indicator.getPosition().y);
			indicatorX += indicator.getSize().x;
		}

		position = sf::Vector2f(indicatorX, indicatorY);
		button->setPosition(position);
		indicatorY = position.y + (default_upgrade_height - default_indicator_height);
		for (auto& indicator : button->getIndicators()) {
			ASSERT_FLOAT_EQ(indicatorX, indicator.getPosition().x);
			ASSERT_FLOAT_EQ(indicatorY, indicator.getPosition().y);
			indicatorX += indicator.getSize().x;
		}
	}

	TEST_F(UpgradeButtonTest, input) {
		button = new UpgradeButton("Test String", sf::Font(), 5);
		ASSERT_TRUE(button->input(sf::Vector2f(), true));
		ASSERT_FALSE(button->input(sf::Vector2f(), false));
		ASSERT_FALSE(button->input(sf::Vector2f(500.F, 900.F), true));
		ASSERT_FALSE(button->input(sf::Vector2f(500.F, 900.F), false));
	}

	TEST_F(UpgradeButtonTest, update_does_not_fail_out_of_range) {
		unsigned short numIndicators = 5;
		button = new UpgradeButton("Test String", sf::Font(), numIndicators);
		numIndicators += 7;
		ASSERT_NO_THROW(button->update(sf::Vector2f(), numIndicators, true));
	}

	TEST_F(UpgradeButtonTest, update_handles_mousePos_correctly) {
		unsigned short numIndicators = 5;
		button = new UpgradeButton("Test String", sf::Font(), numIndicators);
		button->update(sf::Vector2f(-10.F, -10.F), 0, true);
		for (auto& indicator : button->getIndicators()) {
			ASSERT_EQ(sf::Color::Cyan, indicator.getFillColor());
		}
		button->update(sf::Vector2f(), 0, true);
		ASSERT_EQ(sf::Color::Green, button->getIndicators()[0].getFillColor());
	}
}