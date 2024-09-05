#pragma once
#include <GameState.h>
class StageSelectState	: public GameState
{
public:
	StageSelectState();
	void input() override final;
	void update() override final;
	void render() override final;
};