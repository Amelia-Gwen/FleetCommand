#pragma once

#include "IScreen.h"

#include "DisplayPanel.h"
#include "GUIButton.h"
#include "UnitButton.h"
#include "UnitData.h"

namespace fleet {
	class UnitScreen : public IScreen {
	public:
		explicit UnitScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		GUIButton dashboardButton{ sf::Vector2f(game_button_width, game_button_height), "Dashboard", font };
		GUIButton researchButton{ sf::Vector2f(game_button_width, game_button_height), "Research", font };
		GUIButton fleetButton{ sf::Vector2f(game_button_width, game_button_height), "Fleet", font };
		GUIButton worldMapButton{ sf::Vector2f(game_button_width, game_button_height), "World Map", font };

		UnitButton marines{ "Marines", font, UnitBaseCosts::marines };
		UnitButton patrol{ "Patrol Ship", font, UnitBaseCosts::patrol };
		UnitButton corvette{ "Corvette", font, UnitBaseCosts::corvette };
		UnitButton frigate{ "Frigate", font, UnitBaseCosts::frigate };
		UnitButton submarine{ "Submarine", font, UnitBaseCosts::submarine };
		UnitButton destroyer{ "Destroyer", font, UnitBaseCosts::destroyer };
		UnitButton cruiser{ "Cruiser", font, UnitBaseCosts::cruiser };
		UnitButton carrier{ "Carrier", font, UnitBaseCosts::carrier };
		UnitButton tanker{ "Tanker", font, UnitBaseCosts::tanker };
		UnitButton transport{ "Transport", font, UnitBaseCosts::transport };
		UnitButton cargo{ "Cargo", font, UnitBaseCosts::cargo };
		UnitButton missile{ "Missile Ship", font, UnitBaseCosts::missile };

		sf::RectangleShape textDisplay{ sf::Vector2f(research_text_box_width, research_text_box_height) };
		sf::Text description{ "Invalid test string", font };
	};
}