#include "GameStartState.h"
#include <globals.h>
GameStartState::GameStartState()
{
	for (int i = 0; i < 11; i++)
	{
		iRects[i] = { {(i * 255),0},{255,255} };
	}
	xPos = 40.f;
	yPos = -255.f;
}

void GameStartState::input()
{
}

void GameStartState::update()
{
	yPos += 200.f * gTime;

	if (yPos > 645)
	{
		yPos = 645;
	}
}

void GameStartState::render()
{
	sf::Sprite aSpr = {};
	aSpr.setTexture(Cfg::textures.get((int)Cfg::Textures::Count));
	aSpr.setTextureRect(iRects[currRect]);
	aSpr.setPosition({xPos,yPos});
	gWnd.draw(aSpr);
}
