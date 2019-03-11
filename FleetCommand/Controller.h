#pragma once

#include "Model.h"
#include "View.h"

namespace fleet {
	class Controller {
	public:
		explicit Controller(const Model& model, const View& view);

		void input();
	private:
		const Model& Model;
		const View& View;
	};
}