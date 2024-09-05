#pragma once
#include <GameState.h>
#include <memory>
#include <utility>
#include <Stage.h>

class PlayState : public GameState
{
public:
	PlayState();
	void input() override final;
	void update() override final;
	void render() override final;
};