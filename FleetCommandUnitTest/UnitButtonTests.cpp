#include "gtest/gtest.h"

#include "UnitButton.h"

#include "Expressions.h"

#include <Graphics.hpp>

namespace fleet {
	class UnitButtonTest : public testing::Test {
	public:
		void TearDown() override {
			if (button) {
				delete button;
			}
		}
	protected:
		UnitButton* button;
	};

	TEST_F(UnitButtonTest, constructor_accepts_empty_string) {
		button = new UnitButton("", sf::Font(), 5);
		ASSERT_STREQ("", button->getLabelString().toAnsiString().c_str());
	}

	TEST_F(UnitButtonTest, constructor_handles_large_strings) {
		std::string longString = "This is a very long string to test that the constructor of the \
			UnitButton class properly handles very long strings.";
		button = new UnitButton(longString, sf::Font(), 5);
		ASSERT_EQ(longString, button->getLabelString());
	}

	TEST_F(UnitButtonTest, default_label_color_is_white) {
		button = new UnitButton("Test String", sf::Font(), 5);
		ASSERT_EQ(sf::Color::White, button->getTextFillColor());
	}
}