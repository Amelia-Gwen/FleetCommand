#include "View.h"

#include "Screens.h"

#include <utility>

namespace fleet {
	View::View(const Model& model) :
		model{ model }
	{
		window.setFramerateLimit(60);
		//background.loadFromFile("Assets/background.png");
		font.loadFromFile("Assets/a-song-for-jennifer/a-song-for-jennifer.ttf");

		screens.emplace(std::make_pair("Main Menu Screen", std::make_unique<MainMenuScreen>(window, font)));
		screens.emplace(std::make_pair("New Game Screen", std::make_unique<NewGameMenuScreen>(window, font)));

		currentScreen = screens["Main Menu Screen"].get();
	}

	GameEvent View::input()
	{
		GameEvent gameEvent = currentScreen->input();
		checkEvent(gameEvent);
		return gameEvent;
	}

	void View::display()
	{
		window.clear();
		window.draw(backgroundSprite);
		currentScreen->draw();
		window.display();
	}

	void View::checkEvent(GameEvent& gameEvent)
	{
		switch (gameEvent)
		{
		case GameEvent::None:
		case GameEvent::ActionComplete:
			break;
		case GameEvent::OpenNewGame:
			currentScreen = screens["New Game Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		//case GameEvent::OpenLoadGame:
		//	screenState.push(ScreenState::LoadScreen);
		//	gameEvent = GameEvent::ActionComplete;
		//	break;
		//case GameEvent::OpenCustomGame:
		//	screenState.push(ScreenState::CustomScreen);
		//	gameEvent = GameEvent::ActionComplete;
		//	break;
		//case GameEvent::StartCampaign:
		//	screenState.push(ScreenState::WorldMap);
		//	break;
		case GameEvent::ReturnToMainMenu:
			currentScreen = screens["Main Menu Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		//case GameEvent::GoBack:
		//	screenState.pop();
		//	gameEvent = GameEvent::ActionComplete;
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
		default:
			break;
		}
	}
}