#pragma once

#include "IScreen.h"
#include "DisplayPanel.h"

namespace fleet {
	class Dashboard : public IScreen {
	public:
		explicit Dashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
	};
}