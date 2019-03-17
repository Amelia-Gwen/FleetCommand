#pragma once

#include "Model.h"
#include "IScreen.h"
#include "GameEvent.h"
#include "DisplayPanel.h"
#include "Expressions.h"

#include <SFML\Graphics.hpp>

#include <unordered_map>
#include <memory>
#include <string>

namespace fleet {
	/*
	Architecture level class that is responsible for maintaining the window and display.
	*/
	class View {
	public:
		explicit View(const Model& model);

		bool isOpen() const { return window.isOpen(); }
		bool pollEvent(sf::Event& event) { return window.pollEvent(event); }
		void close() { window.close(); }

		GameEvent input();
		void update() { currentScreen->update(); }
		void display();
	private:
		const Model& model;
		sf::RenderWindow window{ sf::VideoMode(view_width, view_height), "Fleet Command" };
		sf::Texture background;
		sf::Sprite backgroundSprite{ background };
		DisplayPanel displayPanel{ model, font };
		sf::Font font;

		std::unordered_map<std::string, std::unique_ptr<IScreen>> screens;
		IScreen* currentScreen;

		void checkEvent(GameEvent& gameEvent);
	};
}