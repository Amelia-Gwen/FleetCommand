#include "CityUpgradeScreen.h"

namespace fleet {
	CityUpgradeScreen::CityUpgradeScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboard.setPosition(game_button_1_x + dashboard_x_offset, game_button_text_y);
		dashboard.setCharacterSize(text_character_size);
		dashboard.setFillColor(sf::Color::Black);
		cityDashboardButton.setPosition(game_button_2_x, game_button_y);
		cityDashboard.setPosition(game_button_2_x + cityname_x_offset, game_button_text_y);
		cityDashboard.setCharacterSize(text_character_size);
		cityDashboard.setFillColor(sf::Color::Black);
		cityMapButton.setPosition(game_button_3_x, game_button_y);
		cityMap.setPosition(game_button_3_x + citymap_x_offset, game_button_text_y);
		cityMap.setCharacterSize(text_character_size);
		cityMap.setFillColor(sf::Color::Black);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMap.setPosition(game_button_4_x + worldmap_x_offset, game_button_text_y);
		worldMap.setCharacterSize(text_character_size);
		worldMap.setFillColor(sf::Color::Black);

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
		cityDashboard.setString(cityName);
		currentLevels = model.cityList()[index].currentLevels();
		cityIndex = index;
	}

	GameEvent CityUpgradeScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (cityDashboardButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::OpenCity;
		}
		else if (cityMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToCityMap;
		}
		else if (worldMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToWorldMap;
		}
		else if (shipyard.getGlobalBounds().contains(mousePos)) {
			if (shipyard.input(mousePos, currentLevels.shipyard,
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
			if (airDefense.input(mousePos, currentLevels.airDefense,
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
			if (groundDefense.input(mousePos, currentLevels.groundDefense,
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
			if (oilProduction.input(mousePos, currentLevels.oilProduction,
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
			if (cashProduction.input(mousePos, currentLevels.cashProduction,
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
			if (researchProduction.input(mousePos, currentLevels.researchProduction,
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
		checkMouseOver(dashboardButton);
		checkMouseOver(cityDashboardButton);
		checkMouseOver(cityMapButton);
		checkMouseOver(worldMapButton);

		if (currentLevels.shipyard < ResearchCosts::cityShipyard.size()) {
			shipyard.update(mousePos, currentLevels.shipyard,
				canAfford(ResearchCosts::cityShipyard[currentLevels.shipyard], model.player()->currentCash()));
		}
		if (currentLevels.airDefense < ResearchCosts::defense.size()) {
			airDefense.update(mousePos, currentLevels.airDefense,
				canAfford(ResearchCosts::defense[currentLevels.airDefense], model.player()->currentCash()));
		}
		if (currentLevels.groundDefense < ResearchCosts::defense.size()) {
			groundDefense.update(mousePos, currentLevels.groundDefense,
				canAfford(ResearchCosts::defense[currentLevels.groundDefense], model.player()->currentCash()));
		}
		if (currentLevels.oilProduction < ResearchCosts::cityProduction.size()) {
			oilProduction.update(mousePos, currentLevels.oilProduction,
				canAfford(ResearchCosts::cityProduction[currentLevels.oilProduction], model.player()->currentCash()));
		}
		if (currentLevels.cashProduction < ResearchCosts::cityProduction.size()) {
			cashProduction.update(mousePos, currentLevels.cashProduction,
				canAfford(ResearchCosts::cityProduction[currentLevels.cashProduction], model.player()->currentCash()));
		}
		if (currentLevels.researchProduction < ResearchCosts::cityProduction.size()) {
			researchProduction.update(mousePos, currentLevels.researchProduction,
				canAfford(ResearchCosts::cityProduction[currentLevels.researchProduction], model.player()->currentCash()));
		}
	}
	void CityUpgradeScreen::draw()
	{
		window.draw(dashboardButton);
		window.draw(dashboard);
		window.draw(cityDashboardButton);
		window.draw(cityDashboard);
		window.draw(cityMapButton);
		window.draw(cityMap);
		window.draw(worldMapButton);
		window.draw(worldMap);
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