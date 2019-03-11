#include "IScreen.h"

namespace fleet {
	IScreen::IScreen(sf::RenderWindow& window, const sf::Font& font) :
		window{ window },
		font{ font }
	{
	}
}