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
		screens.emplace(std::make_pair("Custom Game Screen", std::make_unique<CustomMenuScreen>(window, font)));
		screens.emplace(std::make_pair("World Map Screen", std::make_unique<WorldMapScreen>(window, font, model, displayPanel)));
		screens.emplace(std::make_pair("Dashboard", std::make_unique<Dashboard>(window, font, displayPanel)));
		screens.emplace(std::make_pair("City Dashboard", std::make_unique<CityDashboard>(window, font, displayPanel)));
		screens.emplace(std::make_pair("City Map Screen", std::make_unique<CityMapScreen>(window, font, model, displayPanel)));
		screens.emplace(std::make_pair("City Upgrade Screen", std::make_unique<CityUpgradeScreen>(window, font, displayPanel)));
		screens.emplace(std::make_pair("Unit Screen", std::make_unique<UnitScreen>(window, font, displayPanel)));
		screens.emplace(std::make_pair("Fleet Screen", std::make_unique<FleetScreen>(window, font, displayPanel)));
		screens.emplace(std::make_pair("Research Screen", std::make_unique<ResearchScreen>(window, font, displayPanel)));

		currentScreen = screens["Main Menu Screen"].get();
	}

	void View::releaseGrip()
	{
		if (currentScreen == screens["World Map Screen"].get()) {
			dynamic_cast<WorldMapScreen*>(currentScreen)->releaseGrip();
		}
		else if (currentScreen == screens["City Map Screen"].get()) {
			dynamic_cast<CityMapScreen*>(currentScreen)->releaseGrip();
		}
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
		unsigned index;
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
		case GameEvent::OpenCustomGame:
			currentScreen = screens["Custom Game Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
	    case GameEvent::StartCampaign:
			currentScreen = screens["World Map Screen"].get();
			break;
		case GameEvent::StartGame:
			gameValues = dynamic_cast<CustomMenuScreen*>(screens["Custom Menu Screen"].get())->startValues();
			currentScreen = screens["World Map Screen"].get();
			break;
		case GameEvent::GoToDashboard:
			currentScreen = screens["Dashboard"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::GoToCityMap:
			currentScreen = screens["City Map Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::GoToCityUpgrade:
			currentScreen = screens["City Upgrade Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::GoToWorldMap:
			currentScreen = screens["World Map Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::GoToResearch:
			currentScreen = screens["Research Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::GoToFleet:
			currentScreen = screens["Fleet Screen"].get();
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::GoToUnits:
			currentScreen = screens["Unit Screen"].get();
			break;
		case GameEvent::OpenCity:
			index = dynamic_cast<WorldMapScreen*>(screens["World Map Screen"].get())->activeCity();
			currentScreen = screens["City Dashboard"].get();
			dynamic_cast<CityDashboard*>(currentScreen)->setCity(index);
			gameEvent = GameEvent::ActionComplete;
			break;
		case GameEvent::None:
		case GameEvent::ActionComplete:
		default:
			break;
		}
	}
}