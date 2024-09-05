#pragma once
#include <GameState.h>
class BeatStageState : public GameState
{
public:
	BeatStageState();
	void input() override final;
	void update() override final;
	void render() override final;
};