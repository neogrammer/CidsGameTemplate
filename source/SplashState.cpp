#include <SplashState.h>
#include <globals.h>
#include <SFML/Window/Keyboard.hpp>
SplashState::SplashState()
	: GameState{}
	, bgTexType{Cfg::Textures::SplashBG}
{

}

void SplashState::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { ; }

		gAcc.gameStateMgr->changeState(GameStateType::Title);
	}
}

void SplashState::update()
{
}

void SplashState::render()
{
	sf::Sprite bgSpr = {};
	bgSpr.setTexture(Cfg::textures.get((int)bgTexType));
	bgSpr.setPosition({ 0.f,0.f });
	gWnd.draw(bgSpr);
}
