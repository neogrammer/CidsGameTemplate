#pragma once
#include <GameState.h>

class PresentStageState : public GameState
{
public:
	PresentStageState();
	void input() override final;
	void update() override final;
	void render() override final;
};