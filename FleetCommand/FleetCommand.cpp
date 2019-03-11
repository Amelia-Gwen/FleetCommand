#include "FleetCommand.h"

namespace fleet {
	void FleetCommand::run() {
		while (view.isOpen()) {
			controller.input();
			model.update();
			view.update();
			view.display();
		}
	}
}
