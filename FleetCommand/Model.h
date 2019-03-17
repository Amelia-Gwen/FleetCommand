#pragma once

#include "Coordinate.h"
#include "City.h"

#include <unordered_map>

namespace fleet {
	static const std::unordered_map<std::string, Coordinate> city_names_and_coordinates {
		{"Andwar", Coordinate{9, 1}},
		{"Athol", Coordinate{3, 1}},
		{"Blitzil", Coordinate{1, 6}},
		{"Clint", Coordinate{2, 8}},
		{"Coinenrock", Coordinate{8, 2}},
		{"Dragonopolis", Coordinate{3, 6}},
		{"Everen", Coordinate{8, 1}},
		{"Flagynn", Coordinate{1, 7}},
		{"Galdor", Coordinate{5, 1}},
		{"Hearth", Coordinate{1, 9}},
		{"Iln", Coordinate{2, 7}},
		{"Jelna", Coordinate{3, 9}},
		{"Kali", Coordinate{1, 3}},
		{"Lumin", Coordinate{6, 1}},
		{"Luna", Coordinate{1, 3}},
		{"Markapp", Coordinate{7, 2}},
		{"Morn", Coordinate{2, 1}},
		{"Northrent", Coordinate{1, 1}},
		{"Orion", Coordinate{7, 9}},
		{"Orphan", Coordinate{9, 1}},
		{"Popadieu", Coordinate{9, 2}},
		{"Princess", Coordinate{1, 3}},
		{"Redwind", Coordinate{2, 4}},
		{"Slinder", Coordinate{4, 3}},
		{"Soldier", Coordinate{2, 1}},
		{"Trill", Coordinate{1, 5}},
		{"Ulsar", Coordinate{9, 6}},
		{"Victory", Coordinate{1, 2}},
		{"Wildenstock", Coordinate{8, 5}},
		{"Zwill", Coordinate{1, 1}}
	};
	/*
	Architexture level class responsible for managing the game logic and data.
	*/
	class Model {
	public:
		Model();

		const std::vector<City>& cityList() const { return cities; }
		const City* currentCity() const { return activeCity; }

		void setCity(unsigned index);
		void update();
	private:
		std::vector<City> cities;
		City* activeCity{ nullptr };
	};
}