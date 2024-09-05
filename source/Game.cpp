
#include <Game.h>
#include <type_traits>
#include <string>
#include <variant>
#include <string>
#include <functional>
#include <utility>
#include <globals.h>
#include <SFML/Window/Event.hpp>
#include <globals.h>

Game::Game()
{
	gAcc.gameStateMgr->setup();
	gAcc.animMgr->setup();
	gAcc.entityMgr->setup();
	gAcc.fizzicksMgr->setup();
	gAcc.inputMgr->setup();
	gAcc.scriptMgr->setup();

	gAcc.stageMgr->setup("IntroStage", "assets/data/tilemaps/tilemap_introStage.dat", "assets/data/zones/introStageZoneData.dat", "asssets/data/tilesets/tileset1.data");
	gAcc.gameStateMgr->setupState(GameStateType::Play, "IntroStage");
	/*MenuObject::setupPatches();

	wndw::CreateWindow("MegamanOne", 1600U, 900U);
	
	gWnd.setPosition({ 120, 20 });
	gStateMgr->setGame(this);*/
}

void Game::render()
{
	gAcc.gameStateMgr->render();
}

void Game::input()
{
	gAcc.gameStateMgr->input();
}

Game::~Game()
{
}
//
void* Game::run()
{
	sf::Clock frameTimer;
	::gTime = frameTimer.restart().asSeconds();
	
	while (::gWnd.isOpen())
	{

		// window events handled here
		sf::Event e;
		while (::gWnd.pollEvent(e))
		{
			if ((e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape) || e.type == sf::Event::Closed)
			{
				::gWnd.close();
			}
			
		}

		// if not closed, update and draw the game as needed
		if (::gWnd.isOpen())
		{
			::gTime = frameTimer.restart().asSeconds();	
			
			input();

			
			update();

			
			// now render the screen
			::gWnd.clear(sf::Color(0, 0, 0, 255));
			render();
			::gWnd.display();

			
		}
	}
	return nullptr;
}

void Game::update()
{

	gAcc.gameStateMgr->update();
}

void Game::updateLate()
{
	//StateMgr->updateLate();
}

