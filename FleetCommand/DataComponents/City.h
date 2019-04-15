#pragma once

#include "Coordinate.h"
#include "ResearchData.h"

#include <string>

namespace fleet {
	class City {
	public:
		explicit City(const std::string& name, Coordinate coordinate);

		Coordinate location() const { return coordinate; }
		const std::string& cityName() const { return name; }
		bool isCapital() const { return capital; }
		const CityResearch currentLevels() const { return researchLevels; }

		void setAsCapital() { capital = true; }
	private:
		const std::string name;
		Coordinate coordinate;
		bool capital{ false };
		CityResearch researchLevels;
		int oil;
		int cash;
		int research;
	};
}