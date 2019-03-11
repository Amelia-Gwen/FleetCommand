#pragma once

#include "Controller.h"
#include "Model.h"
#include "View.h"

namespace fleet {
	class FleetCommand {
	public:
		void run();
	private:
		Model model;
		View view{ model };
		Controller controller{ model, view };
	};
}