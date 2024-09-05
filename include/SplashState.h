#pragma once
#include <GameState.h>
#include <Cfg.h>
class SplashState : public GameState
{
	Cfg::Textures bgTexType;
public:
	SplashState();
	void input() override final;
	void update() override final;
	void render() override final;
};