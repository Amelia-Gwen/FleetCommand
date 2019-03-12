#include "View.h"

#include "Screens.h"

#include <utility>

namespace fleet {
	/*
	Sets window framerate limit. Loads resources not localized to individual components.
	Instanciates individual screens and sets non-owning pointer to the screen to be displayed.
	///param: takes a const reference to the model. The View should not be able to update data directly. It is
	simply responsible for displaying it.
	*/
	View::View(const Model& model) :
		model{ model }
	{
		window.setFramerateLimit(60);
		//background.loadFromFile("Assets/background.png");
		font.loadFromFile("Assets/a-song-for-jennifer/a-song-for-jennifer.ttf");

		screens.emplace(std::make_pair("Main Menu Screen", std::make_unique<MainMenuScreen>(window, font)));
		screens.emplace(std::make_pair("New Game Screen", std::make_unique<NewGameMenuScreen>(window, font)));
		screens.emplace(std::make_pair("Load Game Screen", std::make_unique<LoadGameScreen>(window, font)));

		currentScreen = screens["Main Menu Screen"].get();
	}

	/*
	Recieve input from the user, process it internally before passing it on to the Controller.
	Any events that can be handled before passing on the event are handled then a GameEvent::ActionComplete is returned
	///return: GameEvent - a custom enum used to indicate the type of event.
	*/
	GameEvent View::input()
	{
		GameEvent gameEvent = currentScreen->input();
		checkEvent(gameEvent);
		return gameEvent;
	}

	/*
	Render logic for SFML RenderWindow
	*/
	void View::display()
	{
		window.clear();
		window.draw(backgroundSprite);
		currentScreen->draw();
		window.display();
	}

	/*
	Processing function for the View. This alerts the View to perform any needed actions before passing the event to the
	Controller. If the Event is for the View alone, pass a GameEvent::ActionComplete.
	///param: reference to a GameEvent - The reference may be modified.
	*/
	void View::checkEvent(GameEvent& gameEvent)
	{
		switch (gameEvent)
		{
		case GameEvent::OpenNewGame:
			currentScreen = screens["New Game Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::OpenLoadGame:
			currentScreen = screens["Load Game Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::ReturnToMainMenu:
			currentScreen = screens["Main Menu Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
			//case GameEvent::OpenCustomGame:
			//	screenState.push(ScreenState::CustomScreen);
			//	gameEvent = GameEvent::ActionComplete;
			//	break;
			//case GameEvent::StartCampaign:
			//	screenState.push(ScreenState::WorldMap);
			//	break;
		//case GameEvent::GoToDashboard:
		//	screenState.push(ScreenState::Dashboard);
		//	gameEvent = GameEvent::ActionComplete;
		//	break;
		//case GameEvent::GoToResearch:
		//	screenState.push(ScreenState::ResearchScreen);
		//	gameEvent = GameEvent::ActionComplete;
		//	break;
		//case GameEvent::GoToFleet:
		//	screenState.push(ScreenState::FleetScreen);
		//	gameEvent = GameEvent::ActionComplete;
		//	break;
		case GameEvent::None:
		case GameEvent::ActionComplete:
		default:
			break;
		}
	}
}