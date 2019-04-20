#include "pch.h"

#include "../FleetCommand/GUIComponents/UpgradeButton.h"

#include <SFML\Graphics.hpp>

namespace fleet {
	class UpgradeButtonTest : public testing::Test {
	protected:
		UpgradeButton button{ "Test Button", sf::Font(), 5 };
	};
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}