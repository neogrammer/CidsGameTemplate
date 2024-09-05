#pragma once
#include <GameState.h>
class GameSaveState : public GameState
{
public:
	GameSaveState();
	void input() override final;
	void update() override final;
	void render() override final;
};