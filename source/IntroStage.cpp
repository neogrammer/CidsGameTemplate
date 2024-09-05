#include "IntroStage.h"
#include <string>
#include <globals.h>

IntroStage::IntroStage(const std::string& tmapData_, const std::string& zoneData_, const std::string& tsetData_)
	: Stage{ tmapData_, zoneData_, tsetData_ }
{
}

IntroStage::~IntroStage()
{
}

void IntroStage::input()
{
}

void IntroStage::setup()
{
}

void IntroStage::update()
{
}

void IntroStage::render()
{
	gWnd.draw(getZone()->bgSpr);

	for (auto& tile : getZone()->getTiles())
	{
		auto tmp = tile.lock();
		auto pos = tmp->aabb.pos;
		pos.x -= tmp->aabb.texOffset.x;
		pos.y -= tmp->aabb.texOffset.y;
		sf::Sprite tmpSpr = {};
		tmpSpr.setTexture(Cfg::textures.get((int)getTSetTex()));
		tmpSpr.setPosition({pos.x, pos.y});
		tmpSpr.setTextureRect({ { tmp->aabb.texPos }, {tmp->aabb.texRectDims} });
		gWnd.draw(tmpSpr);
	}

		


}
