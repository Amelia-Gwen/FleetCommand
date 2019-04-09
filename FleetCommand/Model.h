#pragma once

#include "Coordinate.h"
#include "City.h"
#include "GameValues.h"
#include "Player.h"

#include <unordered_map>

namespace fleet {
	static const GameValues defaultValues{ 1, 7, Difficulty::Medium, 10000, 1000, 10 };

	static const std::unordered_map<std::string, Coordinate> city_names_and_coordinates {
		{"Andwar", Coordinate{102, 102}}, // Done, Capital
		{"Athol", Coordinate{3, 1}},
		{"Blitzil", Coordinate{1, 6}},
		{"Clint", Coordinate{2, 8}},
		{"Coinenrock", Coordinate{8, 2}},
		{"Dragonopolis", Coordinate{32, 8}}, // Done
		{"Everen", Coordinate{8, 1}},
		{"Flagynn", Coordinate{166, 90}}, // Done, Capital
		{"Galdor", Coordinate{5, 1}},
		{"Hearth", Coordinate{1, 9}},
		{"Iln", Coordinate{215, 44}}, // Done, Capital
		{"Jelna", Coordinate{3, 9}},
		{"Kali", Coordinate{1, 3}},
		{"Lumin", Coordinate{24, 28}}, // Done
		{"Luna", Coordinate{1, 3}},
		{"Markapp", Coordinate{7, 2}},
		{"Morn", Coordinate{2, 1}},
		{"Northrent", Coordinate{86, 6}}, // Done, Capital
		{"Orion", Coordinate{7, 9}},
		{"Orphan", Coordinate{9, 1}},
		{"Popadieu", Coordinate{225, 7}}, // Done, Capital
		{"Princess", Coordinate{1, 3}},
		{"Redwind", Coordinate{57, 114}}, // Done, Capital
		{"Slinder", Coordinate{4, 3}},
		{"Soldier", Coordinate{2, 1}},
		{"Trill", Coordinate{1, 5}},
		{"Ulsar", Coordinate{9, 6}},
		{"Victory", Coordinate{12, 83}}, // Done, Capital
		{"Wildenstock", Coordinate{14, 4}}, // Done, Capital
		{"Zwill", Coordinate{1, 1}}
	};
	/*
	Architexture level class responsible for managing the game logic and data.
	*/
	class Model {
	public:
		Model();

		const std::vector<City>& cityList() const { return cities; }

		void startGame(const GameValues& gameValues = defaultValues);
		void update();
	private:
		std::vector<City> cities;
		std::vector<Player> players;
		Player* currentPlayer{ nullptr };
	};
}