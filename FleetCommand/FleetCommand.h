#pragma once

#include "Controller.h"
#include "Model.h"
#include "View.h"

namespace fleet {
	/*
	Application level class that runs the game loop over Architectural level components.
	*/
	class FleetCommand {
	public:
		void run();
	private:
		Model model;
		View view{ model };
		Controller controller{ model, view };
	};
}