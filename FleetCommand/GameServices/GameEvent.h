#pragma once

/*
Service to express, via enum, a game specific event has occured which can be carried to the controller to be processed.
Any event that can be processed by the entity that created it will take the appropriate action and then pass ActionComplete.
*/

namespace fleet {
	enum class GameEvent
	{
		None,
		ActionComplete,
		OpenNewGame,
		OpenLoadGame,
		ReturnToMainMenu,
		StartCampaign,
		OpenCustomGame,
		StartGame,
		LoadGame,

		//GoToDashboard,
		//GoToResearch,
		//GoToFleet,
		//EndTurn,
		//OpenCity,
		//SaveGame
	};
}