#include "FleetCommand.h"

namespace fleet {
	void FleetCommand::run() {
		Controller.input();
		Model.update();
		View.update();
		View.display();
	}
}
