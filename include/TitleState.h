#pragma once
#include <GameState.h>
#include <Cfg.h>
class TitleState : public GameState
{
	Cfg::Textures bgTexType;
public:
	TitleState();
	void input() override final;
	void update() override final;
	void render() override final;
};
