#pragma once
#include <GameState.h>

class GameStateTransition : public GameState
{
public:
	GameStateTransition();
	void input() override final;
	void update() override final;
	void render() override final;
};