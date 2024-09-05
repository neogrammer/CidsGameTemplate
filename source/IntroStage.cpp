#include "IntroStage.h"
#include <string>
#include <globals.h>

IntroStage::IntroStage(const std::string& tmapData_, const std::string& zoneData_, const std::string& tsetData_)
	: Stage{ tmapData_, zoneData_, tsetData_ }
{
	auto& tmp = getZone()->bgSpr2;
	getZone()->bgSpr2 = {};
	getZone()->bgSpr2.setTexture(*const_cast<sf::Texture*>(getZone()->bgSpr.getTexture()));
	getZone()->bgSpr2.setPosition({getZone()->bgSpr.getPosition().x - getZone()->bgSpr.getTextureRect().width, getZone()->bgSpr.getPosition().y});
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
	getZone()->bgSpr.move({5.f * gTime,0.f});
	getZone()->bgSpr2.move({ 5.f * gTime,0.f });

	if (getZone()->bgSpr2.getPosition().x > 0.f)
	{
		getZone()->bgSpr2.setPosition({ getZone()->bgSpr2.getPosition().x - getZone()->bgSpr2.getTextureRect().width, getZone()->bgSpr2.getPosition().y });
		getZone()->bgSpr.setPosition({ getZone()->bgSpr2.getPosition().x + getZone()->bgSpr2.getTextureRect().width, getZone()->bgSpr2.getPosition().y });

	}

}

void IntroStage::render()
{

	gWnd.draw(getZone()->bgSpr);
	gWnd.draw(getZone()->bgSpr2);


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
