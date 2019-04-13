#pragma once

#include "DisplayPanel.h"
#include "IScreen.h"
#include "Model.h"
#include "ResearchData.h"
#include "UpgradeButton.h"

namespace fleet {
	class ResearchScreen : public IScreen {
	public:
		explicit ResearchScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		const Model& model;
		DisplayPanel& displayPanel;
		sf::RectangleShape dashboardButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text dashboard{ "Dashboard", font };
		sf::RectangleShape unitsButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text units{ "Units", font };
		sf::RectangleShape fleetButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text fleet{ "Fleet", font };
		sf::RectangleShape worldMapButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text worldMap{ "World Map", font };

		UpgradeButton shipyard{ "Shipyard", ResearchMaximums::shpiyardMax };
		UpgradeButton shipTypes{ "Ship Types", ResearchMaximums::shipTypeMax };
		UpgradeButton durability{ "Durability", ResearchMaximums::durabilityMax };
		UpgradeButton firepower{ "Firepower", ResearchMaximums::firepowerMax };
		UpgradeButton hull{ "Hull", ResearchMaximums::hullMax };
		UpgradeButton engine{ "Engines", ResearchMaximums::engineMax };
		UpgradeButton weapons{ "Weapons", ResearchMaximums::weaponMax };
		UpgradeButton fuelEfficieny{ "Fuel Efficiency", ResearchMaximums::fuelEfficiencyMax };
		UpgradeButton oilProduction{ "Oil Production", ResearchMaximums::productionMax };
		UpgradeButton cashProduction{ "Cash Production", ResearchMaximums::productionMax };
		UpgradeButton researchProduction{ "Research Production", ResearchMaximums::productionMax };
	};
}