#include "TitleState.h"
#include <globals.h>
#include <SFML/Window/Keyboard.hpp>
TitleState::TitleState()
	: GameState{}
	, bgTexType{Cfg::Textures::TitleBG}
{
}

void TitleState::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { ;  }

		gAcc.gameStateMgr->changeState(GameStateType::Play);
	}
}

void TitleState::update()
{
}

void TitleState::render()
{
	sf::Sprite bgSpr = {};
	bgSpr.setTexture(Cfg::textures.get((int)bgTexType));
	bgSpr.setPosition({0.f,0.f});
	gWnd.draw(bgSpr);
}
