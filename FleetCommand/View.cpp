#include "View.h"

namespace fleet {
	View::View(const Model& model) :
		model{ model }
	{
		window.setFramerateLimit(60);
		background.loadFromFile("Assets/background.png");
		font.loadFromFile("Assets/a-song-for-jennifer/a-song-for-jennifer.ttf");
	}
}