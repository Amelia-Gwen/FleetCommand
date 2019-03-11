#include "Controller.h"

namespace fleet {
	Controller::Controller(const Model& model, View& view) :
		model{ model },
		view{ view }
	{
	}

	void Controller::input()
	{
		GameEvent gameEvent = view.input();
		processEvent(gameEvent);
	}

	void Controller::processEvent(const GameEvent& gameEvent)
	{
		switch (gameEvent)
		{
		//case GameEvent::StartCampaign:
		//	model.startGame(campaign_enemy_count);
		//	// start game
		//	break;
		//case GameEvent::LoadGame:
		//	// TODO: load game based on load file (with check for empty file) then change gamestate
		//	break;
		//case GameEvent::SaveGame:
		//	// TODO: serialize
		//	break;
		//case GameEvent::EndTurn:
		//	model.endTurn();
		//	//view.returnControl();
		//	break;
		//case GameEvent::OpenCity:
		//	//model.setCity(&model.cityList()[view.city()]);
		//	//view.checkCity();
		//	break;
		case GameEvent::None:
		case GameEvent::ActionComplete:
		default:
			break;
		}
	}
}