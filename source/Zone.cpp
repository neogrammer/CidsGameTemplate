#include "Zone.h"
#include <Portal.h>
#include <iostream>
#include <globals.h>
#include <Tile.h>
Zone::~Zone()
{
}

void Zone::setup(int zoneNum, std::pair<sf::Vector2i, sf::Vector2i> tileCorners, std::vector<std::shared_ptr<Tile> >& tiles_, int cols_, sf::Texture& tex, sf::IntRect iRect_, std::shared_ptr<Zone> north_, std::shared_ptr<Zone> south_, std::shared_ptr<Zone> east_, std::shared_ptr<Zone> west_)
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

	bgSpr = {};
	bgSpr.setTexture(tex);
	if (iRect_ != sf::IntRect{ {0, 0}, { 0,0 } })
		bgSpr.setTextureRect({ { tileCorners.first.x * iRect_.getSize().x , tileCorners.first.y * iRect_.getSize().y }, { (tileCorners.second.x - tileCorners.first.x) * iRect_.getSize().x , (tileCorners.second.y - tileCorners.first.y) * iRect_.getSize().y } });
	bgSpr.setPosition({ 0.f,0.f });

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
	int i = 0;
}


void Zone::input()
{
}

void Zone::update()
{
}

void Zone::render()
{
	if (zoneID == -1)
		return;

	gWnd.draw(bgSpr);
}

std::array<Portal, 4>& Zone::getPortals()
{
	return portals;
}

std::vector<std::weak_ptr<Tile> >& Zone::getTiles()
{
	return tiles;
}


