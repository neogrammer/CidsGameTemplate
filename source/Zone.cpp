#include "Zone.h"
#include <Portal.h>
#include <iostream>
#include <globals.h>
#include <Tile.h>
Zone::~Zone()
{
}

void Zone::setup(int zoneNum, std::pair<sf::Vector2i, sf::Vector2i> tileCorners, std::vector<std::shared_ptr<Tile> >& tiles_, int cols_, 
	sf::Texture& tex, sf::IntRect iRect_, std::shared_ptr<Zone> north_, std::shared_ptr<Zone> south_, std::shared_ptr<Zone> east_, std::shared_ptr<Zone> west_)
{
	zoneID = zoneNum;
	//if (portals[(int)ZoneFace::North].otherSide.lock() == nullptr)
	//{
	//	std::cout << "Wiping a portal's zone ptr already holding onto something" << std::endl;
	//}

	//portals[(int)ZoneFace::North].otherSide.reset();
	//portals[(int)ZoneFace::North].otherSide = north_;

	//if (portals[(int)ZoneFace::East].otherSide.lock() == nullptr)
	//{
	//	std::cout << "Wiping a portal's zone ptr already holding onto something" << std::endl;
	//}

	//portals[(int)ZoneFace::East].otherSide.reset();
	//portals[(int)ZoneFace::East].otherSide = east_;

	//if (portals[(int)ZoneFace::South].otherSide.lock() == nullptr)
	//{
	//	std::cout << "Wiping a portal's zone ptr already holding onto something" << std::endl;
	//}

	//portals[(int)ZoneFace::South].otherSide.reset();
	//portals[(int)ZoneFace::South].otherSide = south_;


	//if (portals[(int)ZoneFace::West].otherSide.lock() == nullptr)
	//{
	//	std::cout << "Wiping a portal's zone ptr already holding onto something" << std::endl;
	//}

	//portals[(int)ZoneFace::West].otherSide.reset();
	//portals[(int)ZoneFace::West].otherSide = west_;

	//bgspr = {};
	//bgspr.setposition({ 0.f,0.f });
	//bgspr.settexture(tex);
	//	bgspr.settexturerect({ { tilecorners.first.x * irect_.getsize().x , tilecorners.first.y * irect_.getsize().y }, { (tilecorners.second.x - tilecorners.first.x) * irect_.getsize().x , (tilecorners.second.y - tilecorners.first.y) * irect_.getsize().y } });
	//if (iRect_ != sf::IntRect{ {0, 0}, { 0,0 } })

	topLeftTile = tileCorners.first;
	bottomRightTile = tileCorners.second;


	int tltileNum = topLeftTile.y * cols_ + topLeftTile.x;
	int brtileNum = bottomRightTile.y * cols_ + bottomRightTile.x;


	int startTileNum = tltileNum;
	int endTileNum = brtileNum;
	tiles.clear();
	int colsInner = tileCorners.second.x - tileCorners.first.x;
	int rowsInner = tileCorners.second.y - tileCorners.first.y;


	tiles.resize(colsInner * rowsInner);

	for (int y = topLeftTile.y; y < bottomRightTile.y; y++)
	{
		for (int x = topLeftTile.x; x < bottomRightTile.x; x++)
		{
			int tileNum = y * cols_ + x;
			auto& t = tiles_[tileNum];
			t->aabb.pos = {(float)(x * iRect_.getSize().x) , (float)(y * iRect_.getSize().y)};
			tiles[(static_cast<std::vector<std::weak_ptr<Tile>, std::allocator<std::weak_ptr<Tile>>>::size_type>(y) - topLeftTile.y) * colsInner + (x - topLeftTile.x)] = t;
		}
	}

	bgSpr.setTexture(Cfg::textures.get((int)Cfg::Textures::SpaceBG));
	bgSpr2.setTexture(Cfg::textures.get((int)Cfg::Textures::SpaceBG));
	bgSpr2.setPosition({ 0.f - (float)bgSpr2.getTextureRect().width, 0.f });


}


void Zone::input()
{

}

void Zone::update()
{
	bgSpr.move({ 5.f * gTime,0.f });
	bgSpr2.move({ 5.f * gTime,0.f });

	if (bgSpr2.getPosition().x > 0.f)
	{
		bgSpr2.setPosition({ bgSpr2.getPosition().x - bgSpr2.getTextureRect().width, bgSpr2.getPosition().y });
		bgSpr.setPosition({ bgSpr2.getPosition().x + bgSpr2.getTextureRect().width, bgSpr2.getPosition().y });

	}
}

void Zone::render()
{
	if (zoneID == -1)
		return;

	gWnd.draw(bgSpr);
	gWnd.draw(bgSpr2);
	
	for (auto& t : tiles)
	{
		sf::Sprite tmp = {};
		tmp.setTexture(Cfg::textures.get((int)gAcc.stageMgr->getStage("IntroStage")->getTSetTex()));
		//gWnd.draw(tmp);
	}
}

std::array<Portal, 4>& Zone::getPortals()
{
	return portals;
}

std::vector<std::weak_ptr<Tile> >& Zone::getTiles()
{
	return tiles;
}


