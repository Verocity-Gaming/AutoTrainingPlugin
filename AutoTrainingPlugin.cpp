#include "pch.h"
#include "AutoTrainingPlugin.h"

// Questions? 
// https://linktr.ee/pidgy

// BakkesMod Macro / init function.
BAKKESMOD_PLUGIN(AutoTrainingPlugin, "Auto Training Plugin", "1.0", PERMISSION_ALL)

// The entry point of your plugin.
void AutoTrainingPlugin::onLoad()
{
	this->Log("This is my first BakkesMod Plugin!!");

	this->LoadHooks();
}

// The exit point of your plugin.
void AutoTrainingPlugin::onUnload()
{
	// Nothing needs to happen here.
}

// The hooks that we bind to function calls in Rocket League.
// If function A occurs, we tell bakkes mod to call our custom method.
void AutoTrainingPlugin::LoadHooks()
{
	gameWrapper->HookEvent("Function TAGame.GameEvent_Soccar_TA.EventMatchEnded", std::bind(&AutoTrainingPlugin::GameEndedEvent, this, std::placeholders::_1));
	gameWrapper->HookEvent("Function TAGame.AchievementManager_TA.HandleMatchEnded", std::bind(&AutoTrainingPlugin::GameEndedEvent, this, std::placeholders::_1));
}

// Custom call hooked when Rocket League executes functions associated with the end of a game.
void AutoTrainingPlugin::GameEndedEvent(std::string name)
{
	cvarManager->executeCommand("load_freeplay");
}

// A custom log wrapper. 
void AutoTrainingPlugin::Log(std::string msg)
{
	cvarManager->log("AutoTrainingPlugin: " + msg);
}
