#include "View.h"

namespace fleet {
	View::View(const Model& model) :
		model{ model },
		window{ sf::VideoMode({2200, 1200}), "FleetCommand" }
	{
		window.setFramerateLimit(60);
        // Don't hard code assets. Provide pipeline to load them so that it can be flexible.
		/*background.loadFromFile("Assets/background.png");
		font.loadFromFile("Assets/a-song-for-jennifer/a-song-for-jennifer.ttf");*/
	}

	void View::update()
	{
		// Process window close event
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
	}
	void View::display()
	{
		window.clear();
		// draw
		window.display();
	}
}