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
	}

	void Model::update()
	{
	}
}