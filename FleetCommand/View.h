#pragma once

#include "Model.h"
#include "IScreen.h"
#include "GameEvent.h"

#include <SFML\Graphics.hpp>

#include <map>
#include <memory>
#include <string>

namespace fleet {
	/*
	Architecture level class that is responsible for maintaining the window and display.
	*/
	class View {
	public:
		explicit View(const Model& model);

		bool isOpen() { return window.isOpen(); }

		GameEvent input() { return currentScreen->input(); }
		void update() { currentScreen->update(); }
		void display();
	private:
		const Model& model;
		sf::RenderWindow window;
		sf::Texture background;
		sf::Sprite backgroundSprite{ background };
		sf::Font font;

		std::map<std::string, std::unique_ptr<IScreen>> screens;
		IScreen* currentScreen;
	};
}