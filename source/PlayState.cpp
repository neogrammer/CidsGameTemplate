#include "PlayState.h"
#include <globals.h>
PlayState::PlayState()
	: GameState{}
{
	
}


void PlayState::input()
{
	currStage.lock()->input();
	//gAcc.stageMgr->input();
}

void PlayState::update()
{
	currStage.lock()->update();
	//gAcc.stageMgr->update();
}

void PlayState::render()
{
	currStage.lock()->render();
	//gAcc.stageMgr->render();
}
