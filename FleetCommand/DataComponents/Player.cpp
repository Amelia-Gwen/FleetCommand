#include "Player.h"

namespace fleet {
	Player::Player(const std::string& name, unsigned startingOil, unsigned startingCash, unsigned startingResearch) :
		name{ name },
		oil{ startingOil },
		cash{ startingCash },
		research{ startingResearch }
	{
	}

	void Player::setAI(Difficulty aiDifficulty)
	{
		switch (aiDifficulty)
		{
		case fleet::Difficulty::Easy:
			controller = std::make_unique<EasyAI>();
			break;
		case fleet::Difficulty::Medium:
			controller = std::make_unique<MediumAI>();
			break;
		case fleet::Difficulty::Hard:
			controller = std::make_unique<HardAI>();
			break;
		default:
			break;
		}
	}
	void Player::setCapital(City* newCapitalCity)
	{
		capitalCity = newCapitalCity;
	}
	void Player::loseCity(City* cityToRemove)
	{
		for (auto it = controlledCities.begin(); it != controlledCities.end(); ++it) {
			if (*it == cityToRemove) {
				controlledCities.erase(it);
				break;
			}
		}
	}
	void Player::takeCity(City* cityToAdd)
	{
		for (auto& city : controlledCities) {
			if (cityToAdd == city) {
				return;
			}
		}

		controlledCities.push_back(cityToAdd);
	}
}