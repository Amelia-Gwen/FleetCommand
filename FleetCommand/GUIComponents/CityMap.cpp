#include "CityMap.h"

namespace fleet {
	CityMap::CityMap()
	{
	}

	void CityMap::setCity(const std::string& name)
	{
		cityName = name;
	}
	GameEvent CityMap::input(const sf::Vector2f& mousePos)
	{
		if (zoomIn.getGlobalBounds().contains(mousePos) && mapScale < maximum_scale)
		{
			++mapScale;
			return GameEvent::ActionComplete;
		}
		else if (center.getGlobalBounds().contains(mousePos))
		{
			// focus on selected tile
			// if no city selected focus on 0,0 center point.
			// do not exceed constraints. map edges must never exist within the bounds of the frame.
			return GameEvent::ActionComplete;
		}
		else if (zoomOut.getGlobalBounds().contains(mousePos) && mapScale > minimum_scale)
		{
			--mapScale;
			return GameEvent::ActionComplete;
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

	void CityMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(map, states); // TODO: Remove. Only for testing
		for (auto& row : cityMap)
		{
			for (auto& cell : row)
			{
				target.draw(cell, states);
			}
		}
		target.draw(zoomIn, states);
		target.draw(center, states);
		target.draw(zoomOut, states);
	}
}