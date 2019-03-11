#pragma once

#include "Model.h"

#include <SFML\Graphics.hpp>

#include <map>

namespace fleet {
	class View {
	public:
		explicit View(const Model& model);

		void input();
		void update();
		void display();
	private:
		const Model& model;
		sf::RenderWindow window;
		sf::Texture background;
		sf::Sprite backgroundSprite{ background };
		sf::Font font;

	};
}