#pragma once

#include "City.h"
#include "Difficulty.h"
#include "ResearchData.h"

#include "IAI.h"
#include "EasyAI.h"
#include "MediumAI.h"
#include "HardAI.h"

#include <memory>
#include <string>
#include <vector>

namespace fleet {
	class Player {
	public:
		explicit Player(const std::string& name, int startingOil, int startingCash, int startingResearch);

		const std::string& playerName() const { return name; }
		const unsigned currentOil() const { return oil; }
		const unsigned currentCash() const { return cash; }
		const unsigned currentResearch() const { return research; }

		void setAI(Difficulty aiDifficulty);
		void setCapital(City* newCapitalCity);

		void loseCity(City* cityToRemove);
		void takeCity(City* cityToAdd);
	private:
		std::unique_ptr<IAI> controller{ nullptr };
		std::string name;
		City* capitalCity;
		std::vector<City*> controlledCities;
		PlayerResearch researchLevels;
		int oil;
		int cash;
		int research;
	};
}