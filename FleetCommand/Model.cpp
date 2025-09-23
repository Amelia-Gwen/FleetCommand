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
		players.clear();
		for (int i = 0; i < gameValues.players; ++i) {
			players.emplace_back(Player("", gameValues.oil, gameValues.cash, gameValues.research));
		}
		for (int i = 0; i < gameValues.computers; ++i) {
			Player newPlayer("", gameValues.oil, gameValues.cash, gameValues.research);
			newPlayer.setAI(gameValues.difficulty);
			players.emplace_back(std::move(newPlayer));
		}

		// TODO: Set capital city.
		// Be sure to add capital and complimentary city to players city index.

		currentPlayer = &players[0];
	}

	void Model::endTurn()
	{
		for (unsigned i = 0; i < players.size(); ++i) {
			if (currentPlayer == &players[i]) {
				if (++i < players.size()) {
					currentPlayer = &players[i];
				}
				else {
					currentPlayer = &players[0];
				}
			}
		}
	}

	void Model::update()
	{
	}
}