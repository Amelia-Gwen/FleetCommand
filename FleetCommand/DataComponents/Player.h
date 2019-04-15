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
		explicit Player(const std::string& name, unsigned startingOil, unsigned startingCash, unsigned startingResearch);

		void setAI(Difficulty aiDifficulty);
		void setCapital(City* newCapitalCity);

		const std::string& playerName() const { return name; }
		unsigned& currentOil() { return oil; }
		unsigned currentOil() const { return oil; }
		unsigned& currentCash() { return cash; }
		unsigned currentCash() const { return cash; }
		unsigned& currentResearch() { return research; }
		unsigned currentResearch() const { return research; }
		PlayerResearch& currentLevels() { return researchLevels; }
		const PlayerResearch& currentLevels() const { return researchLevels; }

		void loseCity(City* cityToRemove);
		void takeCity(City* cityToAdd);
	private:
		std::unique_ptr<IAI> controller{ nullptr };
		std::string name;
		City* capitalCity;
		std::vector<City*> controlledCities;
		PlayerResearch researchLevels;
		unsigned oil;
		unsigned cash;
		unsigned research;
	};
}