#include "CityMap.h"

#include <fstream>

namespace fleet {
	void CityMap::setCity(const std::string& name)
	{
		cityName = name;
		std::string filename = "Assets/CityMaps/" + citySize + "map.txt"; //TODO: make unique for each city
		std::ifstream reader;
		reader.open(filename);

		tileMap.clear();
		int token;
		while (reader >> token) {
			tileValues.push_back(token);
		}

		createTileMap();
	}
	GameEvent CityMap::input(const sf::Vector2f& mousePos)
	{
		if (zoomIn.getGlobalBounds().contains(mousePos) && mapScale < maximum_scale) {
			++mapScale;
			resizeMap();
			return GameEvent::ActionComplete;
		}
		else if (zoomOut.getGlobalBounds().contains(mousePos) && mapScale > minimum_scale) {
			--mapScale;
			resizeMap();
			return GameEvent::ActionComplete;
		}
		else if (map.getGlobalBounds().contains(mousePos)) {
			grab(mousePos);
		}
		// observer mode:
		// only draggable/scalable
		// if battle:
		// observer mode for non-turn

		// when in observer mode then always grabbable
		// when in turn mode but no unit selected then non-unit tiles are grabbable
		// when unit is selected then only non-actionable tiles are grabbable. actionable tiles will be highlighted
		return GameEvent::None;
	}
	void CityMap::update(const sf::Vector2f & mousePos)
	{
		mouseOverButtons(mousePos);
		moveMap(mousePos);
	}

	void CityMap::createTileMap()
	{
		float tileWidth;
		if (citySize == "small") {
			tileWidth = (map_width / 20.f) - (tile_outline * 2.f);
		}
		else {
			tileWidth = (map_width / 40.f) - (tile_outline * 2.f);
		}

		for (unsigned i = 0; i < tileValues.size(); ++i) {
			tileMap.emplace_back(sf::RectangleShape(sf::Vector2f(tileWidth, tile_height)));
			tileMap[i].setOutlineThickness(tile_outline);
			tileMap[i].setOutlineColor(sf::Color::White);
			setTileColor(tileMap[i], tileValues[i]);
			setTilePosition(tileMap[i], i, tileWidth);
		}
	}

	void CityMap::setTileColor(sf::RectangleShape& tile, unsigned value)
	{
		switch (value) {
		case 0:
			tile.setFillColor(sf::Color::Blue);
			break;
		case 1:
			tile.setFillColor(sf::Color::Green);
			break;
		case 2:
			tile.setFillColor(sf::Color::Yellow);
			break;
		case 3:
			tile.setFillColor(sf::Color::Black);
			break;
		case 4:
			tile.setFillColor(sf::Color::Red);
			break;
		case 5:
			tile.setFillColor(sf::Color::Cyan);
			break;
		default:
			break;
		}
	}

	void CityMap::setTilePosition(sf::RectangleShape& tile, unsigned index, float tileWidth)
	{
		int tileNum;
		if (citySize == "small") {
			tileNum = 20;
		}
		else {
			tileNum = 40;
		}
		float x = origin.x + (index % tileNum) * tileWidth + (tile_outline * 2) * (index % tileNum);
		float y = origin.y + (index / tileNum) * tile_height + (tile_outline * 2) * (index / tileNum);

		tile.setPosition(x, y);
	}

	void CityMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& tile : tileMap)
		{
			target.draw(tile, states);
		}
		target.draw(zoomIn, states);
		target.draw(zoomOut, states);
	}
}