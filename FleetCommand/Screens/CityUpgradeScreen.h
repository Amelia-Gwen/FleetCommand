#pragma once

#include "IScreen.h"

#include "DisplayPanel.h"
#include "GUIButton.h"
#include "Model.h"
#include "ResearchData.h"
#include "UpgradeButton.h"

namespace fleet {
	class CityUpgradeScreen : public IScreen {
	public:
		explicit CityUpgradeScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel);

		void setCity(unsigned index);

		unsigned city() const { return cityIndex; };
		const CityResearch& newLevels() const { return currentLevels; }
		unsigned cost() const { return price; }

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		const Model& model;
		DisplayPanel& displayPanel;
		std::string cityName;
		CityResearch currentLevels;
		unsigned cityIndex{ 0 };
		unsigned price{ 0 };

		GUIButton dashboardButton{ sf::Vector2f(game_button_width, game_button_height), "Dashboard", font };
		GUIButton cityDashboardButton{ sf::Vector2f(game_button_width, game_button_height), "", font };
		GUIButton cityMapButton{ sf::Vector2f(game_button_width, game_button_height), "City Map", font };
		GUIButton worldMapButton{ sf::Vector2f(game_button_width, game_button_height), "World Map", font };

		UpgradeButton shipyard{ "Shipyard", ResearchMaximums::shpiyardMax };
		UpgradeButton airDefense{ "Air Defense", ResearchMaximums::defenseMax };
		UpgradeButton groundDefense{ "Ground Defense", ResearchMaximums::defenseMax };
		UpgradeButton oilProduction{ "Oil Production", ResearchMaximums::productionMax };
		UpgradeButton cashProduction{ "Cash Production", ResearchMaximums::productionMax };
		UpgradeButton researchProduction{ "Research Production", ResearchMaximums::productionMax };

		sf::RectangleShape textDisplay{ sf::Vector2f(city_upgrade_text_box_width, city_upgrade_text_box_height) };
		sf::Text description{ "Invalid test string", font };

		bool canAfford(unsigned cost, unsigned resource);
	};
}