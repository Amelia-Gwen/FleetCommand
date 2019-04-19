#include "ResearchScreen.h"

namespace fleet {
	ResearchScreen::ResearchScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		dashboardButton.setLabelOffset(dashboard_x_offset);
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboardButton.setCharacterSize(text_character_size);
		unitsButton.setLabelOffset(unit_x_offset);
		unitsButton.setPosition(game_button_2_x, game_button_y);
		unitsButton.setCharacterSize(text_character_size);
		fleetButton.setLabelOffset(fleet_x_offset);
		fleetButton.setPosition(game_button_3_x, game_button_y);
		fleetButton.setCharacterSize(text_character_size);
		worldMapButton.setLabelOffset(worldmap_x_offset);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMapButton.setCharacterSize(text_character_size);

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

	void ResearchScreen::setLevels(const PlayerResearch& levels)
	{
		currentLevels = levels;
	}

	GameEvent ResearchScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.input(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (unitsButton.input(mousePos)) {
			return GameEvent::GoToUnits;
		}
		else if (fleetButton.input(mousePos)) {
			return GameEvent::GoToFleet;
		}
		else if (worldMapButton.input(mousePos)) {
			return GameEvent::GoToWorldMap;
		}
		else if (shipyard.getGlobalBounds().contains(mousePos)) {
			if (shipyard.input(mousePos,
				canAfford(ResearchCosts::playerShipyard[currentLevels.shipyard], model.player()->currentResearch()))) {
				price = ResearchCosts::playerShipyard[currentLevels.shipyard];
				++currentLevels.shipyard;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (shipTypes.getGlobalBounds().contains(mousePos)) {
			if (shipTypes.input(mousePos, 
				canAfford(ResearchCosts::shipType[currentLevels.shipType], model.player()->currentResearch()))) {
				price = ResearchCosts::shipType[currentLevels.shipType];
				++currentLevels.shipType;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (durability.getGlobalBounds().contains(mousePos)) {
			if (durability.input(mousePos,
				canAfford(ResearchCosts::durability[currentLevels.durability], model.player()->currentResearch()))) {
				price = ResearchCosts::durability[currentLevels.durability];
				++currentLevels.durability;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (firepower.getGlobalBounds().contains(mousePos)) {
			if (firepower.input(mousePos,
				canAfford(ResearchCosts::firepower[currentLevels.firepower], model.player()->currentResearch()))) {
				price = ResearchCosts::firepower[currentLevels.firepower];
				++currentLevels.firepower;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (hull.getGlobalBounds().contains(mousePos)) {
			if (hull.input(mousePos,
				canAfford(ResearchCosts::hull[currentLevels.hull], model.player()->currentResearch()))) {
				price = ResearchCosts::hull[currentLevels.hull];
				++currentLevels.hull;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (engine.getGlobalBounds().contains(mousePos)) {
			if (engine.input(mousePos,
				canAfford(ResearchCosts::engine[currentLevels.engine], model.player()->currentResearch()))) {
				price = ResearchCosts::engine[currentLevels.engine];
				++currentLevels.engine;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (weapons.getGlobalBounds().contains(mousePos)) {
			if (weapons.input(mousePos,
				canAfford(ResearchCosts::weapons[currentLevels.weapons], model.player()->currentResearch()))) {
				price = ResearchCosts::weapons[currentLevels.weapons];
				++currentLevels.weapons;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (fuelEfficieny.getGlobalBounds().contains(mousePos)) {
			if (fuelEfficieny.input(mousePos,
				canAfford(ResearchCosts::fuelEfficiency[currentLevels.fuelEfficiency], model.player()->currentResearch()))) {
				price = ResearchCosts::fuelEfficiency[currentLevels.fuelEfficiency];
				++currentLevels.fuelEfficiency;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (oilProduction.getGlobalBounds().contains(mousePos)) {
			if (oilProduction.input(mousePos,
				canAfford(ResearchCosts::playerProduction[currentLevels.oilProduction], model.player()->currentResearch()))) {
				price = ResearchCosts::playerProduction[currentLevels.oilProduction];
				++currentLevels.oilProduction;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (cashProduction.getGlobalBounds().contains(mousePos)) {
			if (cashProduction.input(mousePos,
				canAfford(ResearchCosts::playerProduction[currentLevels.cashProduction], model.player()->currentResearch()))) {
				price = ResearchCosts::playerProduction[currentLevels.cashProduction];
				++currentLevels.cashProduction;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (researchProduction.getGlobalBounds().contains(mousePos)) {
			if (researchProduction.input(mousePos,
				canAfford(ResearchCosts::playerProduction[currentLevels.researchProduction], model.player()->currentResearch()))) {
				price = ResearchCosts::playerProduction[currentLevels.researchProduction];
				++currentLevels.researchProduction;
				return GameEvent::ResearchAcquired;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}

		return gameEvent;
	}
	void ResearchScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		dashboardButton.update(mousePos);
		unitsButton.update(mousePos);
		fleetButton.update(mousePos);
		worldMapButton.update(mousePos);

		shipyard.update(mousePos, currentLevels.shipyard,
			canAfford(ResearchCosts::playerShipyard[currentLevels.shipyard], model.player()->currentResearch()));
		shipTypes.update(mousePos, currentLevels.shipType,
			canAfford(ResearchCosts::shipType[currentLevels.shipType], model.player()->currentResearch()));
		durability.update(mousePos, currentLevels.durability,
			canAfford(ResearchCosts::durability[currentLevels.durability], model.player()->currentResearch()));
		firepower.update(mousePos, currentLevels.firepower,
			canAfford(ResearchCosts::firepower[currentLevels.firepower], model.player()->currentResearch()));
		hull.update(mousePos, currentLevels.hull,
			canAfford(ResearchCosts::hull[currentLevels.hull], model.player()->currentResearch()));
		engine.update(mousePos, currentLevels.engine,
			canAfford(ResearchCosts::engine[currentLevels.engine], model.player()->currentResearch()));
		weapons.update(mousePos, currentLevels.weapons,
			canAfford(ResearchCosts::weapons[currentLevels.weapons], model.player()->currentResearch()));
		fuelEfficieny.update(mousePos, currentLevels.fuelEfficiency,
			canAfford(ResearchCosts::fuelEfficiency[currentLevels.fuelEfficiency], model.player()->currentResearch()));
		oilProduction.update(mousePos, currentLevels.oilProduction,
			canAfford(ResearchCosts::playerProduction[currentLevels.oilProduction], model.player()->currentResearch()));
		cashProduction.update(mousePos, currentLevels.cashProduction,
			canAfford(ResearchCosts::playerProduction[currentLevels.cashProduction], model.player()->currentResearch()));
		researchProduction.update(mousePos, currentLevels.researchProduction,
			canAfford(ResearchCosts::playerProduction[currentLevels.researchProduction], model.player()->currentResearch()));
	}
	void ResearchScreen::draw()
	{
		window.draw(dashboardButton);
		window.draw(unitsButton);
		window.draw(fleetButton);
		window.draw(worldMapButton);
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

	bool ResearchScreen::canAfford(unsigned cost, unsigned resource)
	{
		return !(resource < cost);
	}
}