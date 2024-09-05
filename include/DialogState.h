#pragma once
#include <GameState.h>

class DialogState : public GameState
{
public:
	DialogState();
	void input() override final;
	void update() override final;
	void render() override final;
};