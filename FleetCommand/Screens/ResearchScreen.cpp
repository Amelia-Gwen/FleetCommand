#include "ResearchScreen.h"

namespace fleet {
	ResearchScreen::ResearchScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboard.setPosition(game_button_1_x + dashboard_x_offset, game_button_text_y);
		dashboard.setCharacterSize(text_character_size);
		dashboard.setFillColor(sf::Color::Black);
		unitsButton.setPosition(game_button_2_x, game_button_y);
		units.setPosition(game_button_2_x + unit_x_offset, game_button_text_y);
		units.setCharacterSize(text_character_size);
		units.setFillColor(sf::Color::Black);
		fleetButton.setPosition(game_button_3_x, game_button_y);
		fleet.setPosition(game_button_3_x + fleet_x_offset, game_button_text_y);
		fleet.setCharacterSize(text_character_size);
		fleet.setFillColor(sf::Color::Black);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMap.setPosition(game_button_4_x + worldmap_x_offset, game_button_text_y);
		worldMap.setCharacterSize(text_character_size);
		worldMap.setFillColor(sf::Color::Black);

		shipyard.setPosition(research_column_one_x, research_row_one_y);
		shipyard.setFont(font);
		shipTypes.setPosition(research_column_two_x, research_row_one_y);
		shipTypes.setFont(font);
		durability.setPosition(research_column_three_x, research_row_one_y);
		durability.setFont(font);
		firepower.setPosition(research_column_four_x, research_row_one_y);
		firepower.setFont(font);
		hull.setPosition(research_column_one_x, research_row_two_y);
		hull.setFont(font);
		engine.setPosition(research_column_two_x, research_row_two_y);
		engine.setFont(font);
		weapons.setPosition(research_column_three_x, research_row_two_y);
		weapons.setFont(font);
		fuelEfficieny.setPosition(research_column_four_x, research_row_two_y);
		fuelEfficieny.setFont(font);
		oilProduction.setPosition(research_column_one_x, research_row_three_y);
		oilProduction.setFont(font);
		cashProduction.setPosition(research_column_two_x, research_row_three_y);
		cashProduction.setFont(font);
		researchProduction.setPosition(research_column_three_x, research_row_three_y);
		researchProduction.setFont(font);

		textDisplay.setPosition(research_text_box_x, research_text_box_y);
		textDisplay.setFillColor(sf::Color::Yellow);
		textDisplay.setOutlineThickness(text_box_outline);
		description.setPosition(research_text_box_x + description_text_offset, research_text_box_y + description_text_offset);
		description.setFillColor(sf::Color::Black);
		description.setCharacterSize(description_character_size);
	}

	GameEvent ResearchScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (unitsButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToUnits;
		}
		else if (fleetButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToFleet;
		}
		else if (worldMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

		return gameEvent;
	}
	void ResearchScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		checkMouseOver(dashboardButton);
		checkMouseOver(unitsButton);
		checkMouseOver(fleetButton);
		checkMouseOver(worldMapButton);
	}
	void ResearchScreen::draw()
	{
		window.draw(dashboardButton);
		window.draw(dashboard);
		window.draw(unitsButton);
		window.draw(units);
		window.draw(fleetButton);
		window.draw(fleet);
		window.draw(worldMapButton);
		window.draw(worldMap);
		window.draw(shipyard);
		window.draw(shipTypes);
		window.draw(durability);
		window.draw(firepower);
		window.draw(hull);
		window.draw(engine);
		window.draw(weapons);
		window.draw(fuelEfficieny);
		window.draw(oilProduction);
		window.draw(cashProduction);
		window.draw(researchProduction);
		window.draw(textDisplay);
		window.draw(description);
		window.draw(displayPanel);
	}
}