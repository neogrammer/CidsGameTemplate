#include "IntroStage.h"
#include <string>
#include <globals.h>

IntroStage::IntroStage(const std::string& tmapData_, const std::string& zoneData_, const std::string& tsetData_)
	: Stage{ tmapData_, zoneData_, tsetData_ }
{
	for (int i = 0; i < 9; i++)
	{
		auto& tmp1 = getZone(i)->bgSpr;
		getZone(i)->bgSpr = {};
		getZone(i)->bgSpr.setTexture(Cfg::textures.get((int)Cfg::Textures::SpaceBG));
		getZone(i)->bgSpr.setPosition({ 0.f,0.f });

		auto& tmp = getZone(i)->bgSpr2;
		getZone(i)->bgSpr2 = {};
		getZone(i)->bgSpr2.setTexture(Cfg::textures.get((int)Cfg::Textures::SpaceBG));
		getZone(i)->bgSpr2.setPosition({ getZone()->bgSpr.getPosition().x - getZone()->bgSpr.getTextureRect().width, getZone()->bgSpr.getPosition().y });
	}
}

IntroStage::~IntroStage()
{
}

void IntroStage::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { ; }
		if (!(currZoneIdx == 0) && !(currZoneIdx == 3) && !(currZoneIdx == 6))
		{
			gAcc.gameStateMgr->pushState(GameStateType::StateTransition);
			gAcc.gameStateMgr->zoneBeforeChange = currZoneIdx;

			zoneAdj = -1;
			gAcc.gameStateMgr->setupState(GameStateType::StateTransition, "IntroStage");

		
	
			
			// play transition_left, if zone.portals[WEST] is not nullptr
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { ; }
		if (!(currZoneIdx == 2) && !(currZoneIdx == 5) && !(currZoneIdx == 8))
		{
			gAcc.gameStateMgr->pushState(GameStateType::StateTransition);
			gAcc.gameStateMgr->zoneBeforeChange = currZoneIdx;

			zoneAdj = 1;
			gAcc.gameStateMgr->setupState(GameStateType::StateTransition, "IntroStage");

			// play transition_right, if zone.portals[EAST] is not nullptr
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { ; }
		if (!(currZoneIdx == 0) && !(currZoneIdx == 1) && !(currZoneIdx == 2))
		{
			gAcc.gameStateMgr->pushState(GameStateType::StateTransition);
			gAcc.gameStateMgr->zoneBeforeChange = currZoneIdx;

			zoneAdj = -3;
			// play transition_up, if zone.portals[NORTH] is not nullptr
			gAcc.gameStateMgr->setupState(GameStateType::StateTransition, "IntroStage");


		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { ; }
		if (!(currZoneIdx == 6) && !(currZoneIdx == 7) && !(currZoneIdx == 8))
		{ 
			gAcc.gameStateMgr->pushState(GameStateType::StateTransition);
			gAcc.gameStateMgr->zoneBeforeChange = currZoneIdx;
			zoneAdj = 3;

			
			gAcc.gameStateMgr->setupState(GameStateType::StateTransition, "IntroStage");

			// play transition_down, if zone.portals[SOUTH] is not nullptr

		}
	}
}

void IntroStage::setup()
{
}

void IntroStage::update()
{
	if (gAcc.gameStateMgr != nullptr)
	{
		if (gAcc.gameStateMgr->getCurrentStateType() != GameStateType::StateTransition)
		{
			// this will run in another state
			//currZoneIdx += zoneAdj;
			zoneAdj = 0;

			getZone()->update();
		}
		else
		{
		

		}

	}

}

void IntroStage::render()
{

	getZone()->render();


	for (auto& tile : getZone()->getTiles())
	{
		auto tmp = tile.lock();
		auto pos = tmp->aabb.pos;
		pos.y -= tmp->aabb.texOffset.y;

		sf::Sprite tmpSpr = {};
		tmpSpr.setPosition({ tile.lock()->aabb.pos.x - tile.lock()->aabb.texOffset.x, tile.lock()->aabb.pos.y - tile.lock()->aabb.texOffset.y });

		tmpSpr.setTexture(Cfg::textures.get((int)getTSetTex()));
		tmpSpr.setTextureRect({ { tile.lock()->aabb.texPos }, {tile.lock()->aabb.texRectDims}});
		gWnd.draw(tmpSpr);
	}

		


}
