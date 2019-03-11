#pragma once

/*
Service to express, via enum, a game specific event has occured which can be carried to the controller to be processed.
*/

namespace fleet {
	enum class GameEvent
	{
		None,
		ActionComplete,



		//OpenNewGame,
		//OpenLoadGame,
		//OpenCustomGame,
		//StartCampaign,

		//ReturnToMainMenu,
		//LoadGame,
		//GoBack,

		//GoToDashboard,
		//GoToResearch,
		//GoToFleet,

		//EndTurn,
		//OpenCity,
		//SaveGame
	};
}