#pragma once
#include <GameState.h>
class GameLoadState : public GameState
{
public:
	GameLoadState();
	void input() override final;
	void update() override final;
	void render() override final;
};