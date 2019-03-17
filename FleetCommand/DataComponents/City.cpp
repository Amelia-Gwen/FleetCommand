#include "City.h"

namespace fleet {
	City::City(const std::string& name, Coordinate coordinate) :
		name{ name },
		coordinate{ coordinate }
	{
	}
}