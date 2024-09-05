#include "PlayState.h"
#include <globals.h>
PlayState::PlayState()
	: GameState{}
{
	
}


void PlayState::input()
{
	gAcc.stageMgr->input();
}

void PlayState::update()
{
	gAcc.stageMgr->update();
}

void PlayState::render()
{
	gAcc.stageMgr->render();
}
