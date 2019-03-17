#pragma once

#include "Coordinate.h"

namespace fleet {
	class City {
	public:
		explicit City(const std::string& name, Coordinate coordinate);

		Coordinate location() const { return coordinate; }
		const std::string& cityName() const { return name; }
	private:
		const std::string name;
		Coordinate coordinate;

		int oil;
		int cash;
		int research;
	};
}