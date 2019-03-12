#pragma once

#include "Model.h"
#include "IScreen.h"
#include "GameEvent.h"

#include <SFML\Graphics.hpp>

#include <map>
#include <memory>
#include <string>

namespace fleet {

	constexpr unsigned view_width = 1200U;
	constexpr unsigned view_height = 800U;
	constexpr float view_width_float = static_cast<float>(view_width);
	constexpr float view_height_float = static_cast<float>(view_height);

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
		sf::RenderWindow window{ sf::VideoMode(view_width, view_height), "Fleet Command" };
		sf::Texture background;
		sf::Sprite backgroundSprite{ background };
		sf::Font font;

		std::map<std::string, std::unique_ptr<IScreen>> screens;
		IScreen* currentScreen;
	};
}