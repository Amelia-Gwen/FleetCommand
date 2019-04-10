#include "DisplayPanel.h"

#include "IScreen.h"

namespace fleet {
	DisplayPanel::DisplayPanel(const Model& model, const sf::Font& font) :
		model{ model },
		font{ font }
	{		
		nameBox.setPosition(panel_1_x, panel_y);
		nameBox.setFillColor(sf::Color::Cyan);
		name.setPosition(name_x, panel_text_y);
		name.setCharacterSize(text_character_size);
		name.setFillColor(sf::Color::Black);
		oilBox.setPosition(panel_2_x, panel_y);
		oilBox.setFillColor(sf::Color::Cyan);
		oil.setPosition(oil_x, panel_text_y);
		oil.setCharacterSize(text_character_size);
		oil.setFillColor(sf::Color::Black);
		cashBox.setPosition(panel_3_x, panel_y);
		cashBox.setFillColor(sf::Color::Cyan);
		cash.setPosition(cash_x, panel_text_y);
		cash.setCharacterSize(text_character_size);
		cash.setFillColor(sf::Color::Black);
		researchBox.setPosition(panel_4_x, panel_y);
		researchBox.setFillColor(sf::Color::Cyan);
		research.setPosition(research_x, panel_text_y);
		research.setCharacterSize(text_character_size);
		research.setFillColor(sf::Color::Black);
	}

	GameEvent DisplayPanel::input(const sf::Vector2f& mousePos)
	{
		return dropDownMenu.input(mousePos);
	}
	void DisplayPanel::update(const sf::Vector2f& mousePos)
	{
		dropDownMenu.update(mousePos);
		name.setString(model.player()->playerName());
		oil.setString(model.player()->currentOil());
		cash.setString(model.player()->currentCash());
		research.setString(model.player()->currentResearch());
	}
	void DisplayPanel::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(dropDownMenu, states);
		target.draw(nameBox, states);
		target.draw(name, states);
		target.draw(oilBox, states);
		target.draw(oil, states);
		target.draw(cashBox, states);
		target.draw(cash, states);
		target.draw(researchBox, states);
		target.draw(research, states);
	}
}