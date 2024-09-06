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
			//t->aabb.pos = {(float)(x * iRect_.getSize().x) , (float)(y * iRect_.getSize().y)};

			tiles[(static_cast<std::vector<std::weak_ptr<Tile>, std::allocator<std::weak_ptr<Tile>>>::size_type>(y) - topLeftTile.y) * colsInner + (x - topLeftTile.x)] = std::make_shared<Tile>();
			auto& a = tiles[(static_cast<std::vector<std::weak_ptr<Tile>, std::allocator<std::weak_ptr<Tile>>>::size_type>(y) - topLeftTile.y) * colsInner + (x - topLeftTile.x)]->aabb;
			auto& b = t->aabb;
			a.attachedToTileset = b.attachedToTileset;
			a.dims = b.dims;
			a.pos = { (float)(x * iRect_.getSize().x) , (float)(y * iRect_.getSize().y) };
			a.texOffset = b.texOffset;
			a.texPos = b.texPos;
			a.texRectDims = b.texRectDims;
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

	gView.setCenter({ (float)((zoneID % 3) + 1.f) * 1600.f - 800.f, (float)((zoneID / 3) + 1) * 900.f - 450.f});
	gWnd.setView(gView);
	for (auto& t : getTiles())
	{
		sf::Sprite tmp = {};
		tmp.setTexture(Cfg::textures.get((int)Cfg::Textures::TSet1));
		tmp.setTextureRect({ {t->aabb.texPos}, {t->aabb.texRectDims} });
		tmp.setPosition({ t->aabb.pos.x - t->aabb.texOffset.x,t->aabb.pos.y - t->aabb.texOffset.y });
		gWnd.draw(tmp);
	}
		gWnd.setView(gWnd.getDefaultView());
	
	
	
}

std::array<Portal, 4>& Zone::getPortals()
{
	return portals;
}

std::vector<std::shared_ptr<Tile> >& Zone::getTiles()
{
	return tiles;
}


