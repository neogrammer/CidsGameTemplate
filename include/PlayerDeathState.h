#pragma once
#include <GameState.h>

class PlayerDeathState : public GameState
{
public:
	PlayerDeathState();
	void input() override final;
	void update() override final;
	void render() override final;
};