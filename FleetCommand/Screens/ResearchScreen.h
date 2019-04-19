#pragma once

#include "IScreen.h"

#include "DisplayPanel.h"
#include "GUIButton.h"
#include "Model.h"
#include "ResearchData.h"
#include "UpgradeButton.h"

namespace fleet {
	class ResearchScreen : public IScreen {
	public:
		explicit ResearchScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel);

		void setLevels(const PlayerResearch& levels);

		const PlayerResearch& newLevels() const { return currentLevels; };
		unsigned cost() const { return price; };

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		const Model& model;
		DisplayPanel& displayPanel;
		PlayerResearch currentLevels;
		unsigned price{ 0 };

		GUIButton dashboardButton{ sf::Vector2f(game_button_width, game_button_height), "Dashboard", font };
		GUIButton unitsButton{ sf::Vector2f(game_button_width, game_button_height), "Units", font };
		GUIButton fleetButton{ sf::Vector2f(game_button_width, game_button_height), "Fleet", font };
		GUIButton worldMapButton{ sf::Vector2f(game_button_width, game_button_height), "World Map", font };

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

		sf::RectangleShape textDisplay{ sf::Vector2f(research_text_box_width, research_text_box_height) };
		sf::Text description{ "Invalid test string", font };

		bool canAfford(unsigned cost, unsigned resource);
	};
}