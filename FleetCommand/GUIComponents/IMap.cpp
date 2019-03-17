#include "IMap.h"

namespace fleet {
	IMap::IMap()
	{
		worldMap.loadFromFile("Assets/WorldMap.png");
		map.setTexture(&worldMap);
		zoomIn.setPosition(zoom_in_x, map_button_y);
		center.setPosition(center_x, map_button_y);
		zoomOut.setPosition(zoom_out_x, map_button_y);
	}

	void IMap::setPosition(float x, float y)
	{
		mapX = x;
		mapY = y;
		map.setPosition(x, y);
	}

	void IMap::update(const sf::Vector2f & mousePos)
	{
		mouseOverButtons(mousePos);
		moveMap(mousePos);
	}

	void IMap::grab(const sf::Vector2f& mousePos)
	{
		grabbed = true;
		mouseWasAt = mousePos;
	}
	void IMap::resizeMap()
	{
		float scale = 0.8F + (static_cast<float>(mapScale) * 0.2F);
		float map_x_offset = ((map.getSize().x * map.getScale().x) - (map_width * scale)) / 2.F;
		float map_y_offset = ((map.getSize().y * map.getScale().y) - (map_height * scale)) / 2.F;
		float x = map.getPosition().x + map_x_offset;
		float y = map.getPosition().y + map_y_offset;
		map.setScale(scale, scale);

		constrainMapCoordinates(x, y);

		map.setPosition(x, y);
	}
	void IMap::moveMap(const sf::Vector2f& newPos)
	{
		if (grabbed) {
			sf::Vector2f moved = newPos - mouseWasAt;
			float x = map.getPosition().x + moved.x;
			float y = map.getPosition().y + moved.y;

			constrainMapCoordinates(x, y);

			map.setPosition(x, y);
			mouseWasAt = newPos;
		}
	}
	void IMap::constrainMapCoordinates(float& x, float& y)
	{
		if (x > mapX) {
			x = mapX;
		}
		else if (x < -(map_width * map.getScale().x - map_width) + mapX) {
			x = -(map_width * map.getScale().x - map_width) + mapX;
		}

		if (y > mapY) {
			y = mapY;
		}
		else if (y < -(map_height * map.getScale().y - map_height) + mapY) {
			y = -(map_height * map.getScale().y - map_height) + mapY;
		}
	}
	void IMap::mouseOverButtons(const sf::Vector2f& mousePos)
	{
		if (zoomIn.getGlobalBounds().contains(mousePos)) {
			if (mapScale < maximum_scale) {
				zoomIn.setFillColor(sf::Color::Green);
			}
			else {
				zoomIn.setFillColor(sf::Color::Red);
			}
		}
		else {
			zoomIn.setFillColor(sf::Color::White);
		}

		if (center.getGlobalBounds().contains(mousePos)) {
			center.setFillColor(sf::Color::Green);
		}
		else {
			center.setFillColor(sf::Color::White);
		}

		if (zoomOut.getGlobalBounds().contains(mousePos)) {
			if (mapScale > minimum_scale) {
				zoomOut.setFillColor(sf::Color::Green);
			}
			else {
				zoomOut.setFillColor(sf::Color::Red);
			}
		}
		else {
			zoomOut.setFillColor(sf::Color::White);
		}
	}
}