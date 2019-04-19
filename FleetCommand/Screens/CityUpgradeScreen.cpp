#include "CityUpgradeScreen.h"

namespace fleet {
	CityUpgradeScreen::CityUpgradeScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		dashboardButton.setLabelOffset(dashboard_x_offset);
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboardButton.setCharacterSize(text_character_size);
		cityDashboardButton.setLabelOffset(cityname_x_offset);
		cityDashboardButton.setPosition(game_button_2_x, game_button_y);
		cityDashboardButton.setCharacterSize(text_character_size);
		cityMapButton.setLabelOffset(citymap_x_offset);
		cityMapButton.setPosition(game_button_3_x, game_button_y);
		cityMapButton.setCharacterSize(text_character_size);
		worldMapButton.setLabelOffset(worldmap_x_offset);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMapButton.setCharacterSize(text_character_size);

		shipyard.setPosition(city_upgrade_column_one_x, city_upgrade_row_one_y);
		shipyard.setFont(font);
		airDefense.setPosition(city_upgrade_column_two_x, city_upgrade_row_one_y);
		airDefense.setFont(font);
		groundDefense.setPosition(city_upgrade_column_three_x, city_upgrade_row_one_y);
		groundDefense.setFont(font);
		oilProduction.setPosition(city_upgrade_column_one_x, city_upgrade_row_two_y);
		oilProduction.setFont(font);
		cashProduction.setPosition(city_upgrade_column_two_x, city_upgrade_row_two_y);
		cashProduction.setFont(font);
		researchProduction.setPosition(city_upgrade_column_three_x, city_upgrade_row_two_y);
		researchProduction.setFont(font);

		textDisplay.setPosition(city_upgrade_text_box_x, city_upgrade_text_box_y);
		textDisplay.setFillColor(sf::Color::Yellow);
		textDisplay.setOutlineThickness(text_box_outline);
		description.setPosition(city_upgrade_text_box_x + description_text_offset,
			city_upgrade_text_box_y + description_text_offset);
		description.setFillColor(sf::Color::Black);
		description.setCharacterSize(description_character_size);
	}

	void CityUpgradeScreen::setCity(unsigned index)
	{
		cityName = model.cityList()[index].cityName();
		cityDashboardButton.setLabel(cityName);
		currentLevels = model.cityList()[index].currentLevels();
		cityIndex = index;
	}

	GameEvent CityUpgradeScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.input(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (cityDashboardButton.input(mousePos)) {
			return GameEvent::OpenCity;
		}
		else if (cityMapButton.input(mousePos)) {
			return GameEvent::GoToCityMap;
		}
		else if (worldMapButton.input(mousePos)) {
			return GameEvent::GoToWorldMap;
		}
		else if (shipyard.getGlobalBounds().contains(mousePos)) {
			if (shipyard.input(mousePos,
				canAfford(ResearchCosts::cityShipyard[currentLevels.shipyard], model.player()->currentCash()))) {
				price = ResearchCosts::cityShipyard[currentLevels.shipyard];
				++currentLevels.shipyard;
				return GameEvent::CityUpgradePurchased;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (airDefense.getGlobalBounds().contains(mousePos)) {
			if (airDefense.input(mousePos,
				canAfford(ResearchCosts::defense[currentLevels.airDefense], model.player()->currentCash()))) {
				price = ResearchCosts::defense[currentLevels.airDefense];
				++currentLevels.airDefense;
				return GameEvent::CityUpgradePurchased;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (groundDefense.getGlobalBounds().contains(mousePos)) {
			if (groundDefense.input(mousePos,
				canAfford(ResearchCosts::defense[currentLevels.groundDefense], model.player()->currentCash()))) {
				price = ResearchCosts::defense[currentLevels.groundDefense];
				++currentLevels.groundDefense;
				return GameEvent::CityUpgradePurchased;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (oilProduction.getGlobalBounds().contains(mousePos)) {
			if (oilProduction.input(mousePos,
				canAfford(ResearchCosts::cityProduction[currentLevels.oilProduction], model.player()->currentCash()))) {
				price = ResearchCosts::cityProduction[currentLevels.oilProduction];
				++currentLevels.oilProduction;
				return GameEvent::CityUpgradePurchased;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (cashProduction.getGlobalBounds().contains(mousePos)) {
			if (cashProduction.input(mousePos,
				canAfford(ResearchCosts::cityProduction[currentLevels.cashProduction], model.player()->currentCash()))) {
				price = ResearchCosts::cityProduction[currentLevels.cashProduction];
				++currentLevels.cashProduction;
				return GameEvent::CityUpgradePurchased;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}
		else if (researchProduction.getGlobalBounds().contains(mousePos)) {
			if (researchProduction.input(mousePos,
				canAfford(ResearchCosts::cityProduction[currentLevels.researchProduction], model.player()->currentCash()))) {
				price = ResearchCosts::cityProduction[currentLevels.researchProduction];
				++currentLevels.researchProduction;
				return GameEvent::CityUpgradePurchased;
			}
			else {
				return GameEvent::ActionComplete;
			}
		}

		return gameEvent;
	}
	void CityUpgradeScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		dashboardButton.update(mousePos);
		cityDashboardButton.update(mousePos);
		cityMapButton.update(mousePos);
		worldMapButton.update(mousePos);

		shipyard.update(mousePos, currentLevels.shipyard,
			canAfford(ResearchCosts::cityShipyard[currentLevels.shipyard], model.player()->currentCash()));
		airDefense.update(mousePos, currentLevels.airDefense,
			canAfford(ResearchCosts::defense[currentLevels.airDefense], model.player()->currentCash()));
		groundDefense.update(mousePos, currentLevels.groundDefense,
			canAfford(ResearchCosts::defense[currentLevels.groundDefense], model.player()->currentCash()));
		oilProduction.update(mousePos, currentLevels.oilProduction,
			canAfford(ResearchCosts::cityProduction[currentLevels.oilProduction], model.player()->currentCash()));
		cashProduction.update(mousePos, currentLevels.cashProduction,
			canAfford(ResearchCosts::cityProduction[currentLevels.cashProduction], model.player()->currentCash()));
		researchProduction.update(mousePos, currentLevels.researchProduction,
			canAfford(ResearchCosts::cityProduction[currentLevels.researchProduction], model.player()->currentCash()));
	}
	void CityUpgradeScreen::draw()
	{
		window.draw(dashboardButton);
		window.draw(cityDashboardButton);
		window.draw(cityMapButton);
		window.draw(worldMapButton);
		window.draw(shipyard);
		window.draw(airDefense);
		window.draw(groundDefense);
		window.draw(oilProduction);
		window.draw(cashProduction);
		window.draw(researchProduction);
		window.draw(textDisplay);
		window.draw(description);
		window.draw(displayPanel);
	}

	bool CityUpgradeScreen::canAfford(unsigned cost, unsigned resource)
	{
		return !(resource < cost);
	}
}