#include "gtest/gtest.h"

#include "GUIButton.h"

#include <Graphics.hpp>

namespace fleet {
	class GUIButtonTest : public testing::Test {
	protected:
		GUIButton button{ sf::Vector2f(50.F, 50.F), "Test String", sf::Font() };
	};
}