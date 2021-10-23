#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"

#pragma comment( lib, "pluginsdk.lib" )

// Questions? 
// https://linktr.ee/pidgy

class AutoTrainingPlugin : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	virtual void onLoad();
	virtual void onUnload(); 

	void LoadHooks(); 
	void GameEndedEvent(std::string name);

private:
	void Log(std::string msg);
};

