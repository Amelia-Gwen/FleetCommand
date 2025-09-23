#pragma once

#include "Coordinate.h"
#include "City.h"
#include "GameValues.h"
#include "Player.h"
#include "ResearchData.h"

#include <unordered_map>

namespace fleet {
	static const GameValues defaultValues{ 1, 7, Difficulty::Medium, 10000, 1000, 10 };

	static const std::unordered_map<std::string, Coordinate> city_names_and_coordinates {
		{"Andwar", Coordinate{102, 102}}, // Done, Capital
		{"Athol", Coordinate{40, 50}},
		{"Blitzil", Coordinate{70, 80}},
		{"Clint", Coordinate{88, 70}},
		{"Coinenrock", Coordinate{99, 60}},
		{"Dragonopolis", Coordinate{32, 8}}, // Done
		{"Everen", Coordinate{114, 30}},
		{"Flagynn", Coordinate{166, 90}}, // Done, Capital
		{"Galdor", Coordinate{62, 103}}, // Done
		{"Hearth", Coordinate{188, 40}},
		{"Iln", Coordinate{215, 44}}, // Done, Capital
		{"Jelna", Coordinate{200, 110}},
		{"Kali", Coordinate{33, 880}},
		{"Lumin", Coordinate{24, 27}}, // Done
		{"Luna", Coordinate{46, 42}}, // Done
		{"Markapp", Coordinate{66, 44}},
		{"Morn", Coordinate{81, 20}},
		{"Northrent", Coordinate{86, 6}}, // Done, Capital
		{"Orion", Coordinate{26, 75}}, // Done
		{"Orphan", Coordinate{158, 99}},
		{"Popadieu", Coordinate{225, 7}}, // Done, Capital
		{"Princess", Coordinate{180, 830}},
		{"Redwind", Coordinate{57, 114}}, // Done, Capital
		{"Slinder", Coordinate{70, 37}},
		{"Soldier", Coordinate{40, 90}},
		{"Trill", Coordinate{90, 104}},
		{"Ulsar", Coordinate{150, 66}},
		{"Victory", Coordinate{12, 83}}, // Done, Capital
		{"Wildenstock", Coordinate{14, 4}}, // Done, Capital
		{"Zwill", Coordinate{210, 33}}
	};

	/*
	Architexture level class responsible for managing the game logic and data.
	*/
	class Model {
	public:
		Model();

		std::vector<City>& cityList() { return cities; }
		const std::vector<City>& cityList() const { return cities; }

		Player* player() { return currentPlayer; }
		const Player* player() const { return currentPlayer; }

		void startGame(const GameValues& gameValues = defaultValues);
		void endTurn();

		void update();
	private:
		std::vector<City> cities;
		std::vector<Player> players;
		Player* currentPlayer{ nullptr };
	};
}