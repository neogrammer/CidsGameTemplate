#pragma once
#include <GameState.h>

class GameStartState : public GameState
{
public:
	GameStartState();
	void input() override final;
	void update() override final;
	void render() override final;
};