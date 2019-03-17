#include "DropDownMenu.h"

#include "IScreen.h"

namespace fleet {
	DropDownMenu::DropDownMenu(const sf::Font& font) :
		font{ font }
	{
		menuButton.setPosition(drop_menu_x, drop_menu_y);
		menu.setPosition(drop_menu_text_x, menu_text_y);
		menu.setCharacterSize(text_character_size);
		menu.setFillColor(sf::Color::Black);
		saveButton.setPosition(drop_menu_x, save_y);
		save.setPosition(drop_menu_text_x, save_text_y);
		save.setCharacterSize(text_character_size);
		save.setFillColor(sf::Color::Black);
		exitButton.setPosition(drop_menu_x, exit_y);
		exit.setPosition(drop_menu_text_x, exit_text_y);
		exit.setCharacterSize(text_character_size);
		exit.setFillColor(sf::Color::Black);
	}

	GameEvent DropDownMenu::input(const sf::Vector2f& mousePos)
	{
		if (menuButton.getGlobalBounds().contains(mousePos)) {
			menuOpen = !menuOpen;
			return GameEvent::ActionComplete;
		}
		else if (menuOpen && saveButton.getGlobalBounds().contains(mousePos)) {
			menuOpen = false;
			return GameEvent::SaveGame;
		}
		else if (menuOpen && exitButton.getGlobalBounds().contains(mousePos)) {
			// TODO: check for confirmation - confirmation should override all other input
			menuOpen = false;
			return GameEvent::ReturnToMainMenu;
		}

		return GameEvent::None;
	}
	void DropDownMenu::update(const sf::Vector2f& mousePos)
	{
		mouseOverButtons(mousePos);
	}
	void DropDownMenu::draw(sf::RenderWindow& window)
	{
		window.draw(menuButton);
		window.draw(menu);
		if (menuOpen)
		{
			window.draw(saveButton);
			window.draw(save);
			window.draw(exitButton);
			window.draw(exit);
		}
	}

	void DropDownMenu::mouseOverButtons(const sf::Vector2f& mousePos)
	{
		if (menuButton.getGlobalBounds().contains(mousePos)) {
			menuButton.setFillColor(sf::Color::Green);
		}
		else {
			menuButton.setFillColor(sf::Color::Cyan);
		}

		if (menuOpen && saveButton.getGlobalBounds().contains(mousePos)) {
			saveButton.setFillColor(sf::Color::Green);
		}
		else {
			saveButton.setFillColor(sf::Color::Cyan);
		}

		if (menuOpen && exitButton.getGlobalBounds().contains(mousePos)) {
			exitButton.setFillColor(sf::Color::Green);
		}
		else {
			exitButton.setFillColor(sf::Color::Cyan);
		}
	}
}