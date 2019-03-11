#pragma once

#include "GameEvent.h"

#include <SFML\Graphics.hpp>

namespace fleet {
	class IScreen {
	public:
		explicit IScreen(sf::RenderWindow& window, sf::Font& font);
		virtual ~IScreen() = default;

		virtual GameEvent input() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
	private:
		sf::RenderWindow& window;
		sf::Font& font;
	};
}