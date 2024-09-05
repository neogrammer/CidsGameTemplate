#pragma once
#include <GameState.h>
class GameMenuState : public GameState
{
public:
	GameMenuState();
	void input() override final;
	void update() override final;
	void render() override final;
};