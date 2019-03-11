#include "View.h"

namespace fleet {
	View::View(const Model& model) :
		model{ model }
	{
		window.setFramerateLimit(60);
        // Don't hard code assets. Provide pipeline to load them so that it can be flexible.
		/*background.loadFromFile("Assets/background.png");
		font.loadFromFile("Assets/a-song-for-jennifer/a-song-for-jennifer.ttf");*/
	}

	void View::input()
	{
	}
	void View::update()
	{
	}
	void View::display()
	{
	}
}