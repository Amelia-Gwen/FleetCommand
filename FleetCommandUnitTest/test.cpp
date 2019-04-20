#include "gtest/gtest.h"

#include "UpgradeButton.h"

#include <SFML\Graphics.hpp>

namespace fleet {
	class UpgradeButtonTest : public testing::Test {
	protected:
		sf::Font font;
		UpgradeButton button{ "Test Button", sf::Font(), 5 };
	};

	TEST_F(UpgradeButtonTest, setPosition) {
		sf::Vector2f position{ 0.F, 0.F };
		button.setPosition(position);
		EXPECT_FLOAT_EQ(position.x, button.getPosition().x);
		EXPECT_FLOAT_EQ(position.y, button.getPosition().y);
		button.setPosition(0.f, 0.f);
		EXPECT_FLOAT_EQ(position.x, button.getPosition().x);
		EXPECT_FLOAT_EQ(position.y, button.getPosition().y);
		button.setPosition(sf::Vector2f());
		EXPECT_FLOAT_EQ(position.x, button.getPosition().x);
		EXPECT_FLOAT_EQ(position.y, button.getPosition().y);
		button.setPosition(200.F, 200.F);
		EXPECT_NE(position.x, button.getPosition().x);
		EXPECT_NE(position.y, button.getPosition().y);
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}