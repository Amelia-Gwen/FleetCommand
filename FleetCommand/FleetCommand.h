#pragma once

#include "Controller.h"
#include "Model.h"
#include "View.h"

namespace fleet {

	class FleetCommand {
	public:
		void run();
	private:
		Model Model;
		View View{ Model };
		Controller Controller{ Model, View };
	};

}