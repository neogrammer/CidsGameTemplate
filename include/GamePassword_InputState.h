#pragma once
#include <GameState.h>
class GamePassword_InputState : public GameState
{
public:
	GamePassword_InputState();
	void input() override final;
	void update() override final;
	void render() override final;
};