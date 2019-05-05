#include "gtest/gtest.h"

#include "GUIButton.h"

#include "Expressions.h"

#include <Graphics.hpp>

namespace fleet {
	class GUIButtonTest : public testing::Test {
	public:
		void TearDown() override {
			if (button) {
				delete button;
			}
		}
	protected:
		GUIButton* button;
	};

	TEST_F(GUIButtonTest, constructor_accepts_empty_string) {
		button = new GUIButton(sf::Vector2f(), "", sf::Font());
		ASSERT_STREQ("", button->getLabelString().toAnsiString().c_str());
	}

	TEST_F(GUIButtonTest, constructor_handles_large_strings) {
		std::string longString = "This is a very long string to test that the constructor of the \
			UpgradeButton class properly handles very long strings.";
		button = new GUIButton(sf::Vector2f(), longString, sf::Font());
		ASSERT_EQ(longString, button->getLabelString());
	}

	TEST_F(GUIButtonTest, button_is_cyan) {
		button = new GUIButton(sf::Vector2f(), "", sf::Font());
		ASSERT_EQ(sf::Color::Cyan, button->getButton().getFillColor());
	}

	TEST_F(GUIButtonTest, input) {
		button = new GUIButton(sf::Vector2f(10.F, 10.F), "", sf::Font());
		ASSERT_TRUE(button->input(sf::Vector2f(5.F, 5.F)));
		ASSERT_FALSE(button->input(sf::Vector2f(900.F, 900.F)));
	}

	TEST_F(GUIButtonTest, button_can_be_deactivated_and_reactivated) {
		button = new GUIButton(sf::Vector2f(10.F, 10.F), "", sf::Font());
		ASSERT_TRUE(button->input(sf::Vector2f(5.F, 5.F)));
		button->setActive(false);
		ASSERT_FALSE(button->input(sf::Vector2f(5.F, 5.F)));
		button->setActive(true);
		ASSERT_TRUE(button->input(sf::Vector2f(5.F, 5.F)));
	}

	TEST_F(GUIButtonTest, update_turns_green_and_back_to_blue) {
		button = new GUIButton(sf::Vector2f(10.F, 10.F), "", sf::Font());
		button->update(sf::Vector2f(5.F, 5.F));
		ASSERT_EQ(sf::Color::Green, button->getButton().getFillColor());
		button->update(sf::Vector2f(900.F, 900.F));
		ASSERT_EQ(sf::Color::Cyan, button->getButton().getFillColor());
	}
}