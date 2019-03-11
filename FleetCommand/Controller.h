#pragma once

#include "Model.h"
#include "View.h"
#include "GameEvent.h"

namespace fleet {
	class Controller {
	public:
		explicit Controller(const Model& model, View& view);

		void input();
	private:
		const Model& model;
		View& view;

		void processEvent(const GameEvent& gameEvent);
	};
}