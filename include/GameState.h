#pragma once
#include <game_state_types.h>

class GameState
{
protected:
	GameStateType type;
public:
	virtual ~GameState();

	virtual void input() = 0; 
		virtual void update() = 0;
		virtual void render() = 0;
		GameStateType getType();
};