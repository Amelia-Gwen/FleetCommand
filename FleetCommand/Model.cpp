#include "Model.h"

namespace fleet {
	Model::Model()
	{
		for (auto& city : city_names_and_coordinates) {
			cities.emplace_back(City(city.first, city.second));
		}
	}

	void Model::startGame(const GameValues& gameValues)
	{
		// TODO: add capital cities from list
		for (int i = 0; i < gameValues.players; ++i) {
			Player newPlayer("", gameValues.oil, gameValues.cash, gameValues.research);
			players.emplace_back(std::move(newPlayer));
		}
		for (int i = 0; i < gameValues.computers; ++i) {
			Player newPlayer("", gameValues.oil, gameValues.cash, gameValues.research);
			newPlayer.setAI(gameValues.difficulty);
			players.emplace_back(std::move(newPlayer));
		}

		currentPlayer = &players[0];
	}

	void Model::update()
	{
	}
}