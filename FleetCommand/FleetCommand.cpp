#include "FleetCommand.h"

namespace fleet {
	/*
	Game loop function.
	*/
	void FleetCommand::run() {
		while (view.isOpen()) {
			controller.input();
			model.update();
			view.update();
			view.display();
		}
	}
}
