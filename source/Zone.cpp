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
	if (portals[(int)ZoneFace::North].otherSide.lock() == nullptr)
	{
		std::cout << "Wiping a portal's zone ptr already holding onto something" << std::endl;
	}

	portals[(int)ZoneFace::North].otherSide.reset();
	portals[(int)ZoneFace::North].otherSide = north_;

	if (portals[(int)ZoneFace::East].otherSide.lock() == nullptr)
	{
		std::cout << "Wiping a portal's zone ptr already holding onto something" << std::endl;
	}

	portals[(int)ZoneFace::East].otherSide.reset();
	portals[(int)ZoneFace::East].otherSide = east_;

	if (portals[(int)ZoneFace::South].otherSide.lock() == nullptr)
	{
		std::cout << "Wiping a portal's zone ptr already holding onto something" << std::endl;
	}

	portals[(int)ZoneFace::South].otherSide.reset();
	portals[(int)ZoneFace::South].otherSide = south_;


	if (portals[(int)ZoneFace::West].otherSide.lock() == nullptr)
	{
		std::cout << "Wiping a portal's zone ptr already holding onto something" << std::endl;
	}

	portals[(int)ZoneFace::West].otherSide.reset();
	portals[(int)ZoneFace::West].otherSide = west_;

	bgSpr = {};
	bgSpr.setTexture(tex);
	if (iRect_ != sf::IntRect{ {0, 0}, { 0,0 } })
		bgSpr.setTextureRect(iRect_);
	bgSpr.setPosition({ 0.f,0.f });

	topLeftTile = tileCorners.first;
	bottomRightTile = tileCorners.second;

	int x = topLeftTile.x;
	int y = topLeftTile.y;

	int startTileNum = y * cols_ + x;

	x = bottomRightTile.x;
	y = bottomRightTile.y;

	int endTileNum = y * cols_ + x;
	tiles.clear();
	int colsInner = bottomRightTile.x - topLeftTile.x;
	int rowsInner = bottomRightTile.y - topLeftTile.y;


	tiles.reserve(colsInner * rowsInner);

	for (int i = startTileNum; i <= endTileNum; i++)
	{
		auto& t = tiles_[i];
		tiles.push_back(t);
	}

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

std::vector<std::weak_ptr<Tile> >& Zone::getTiles()
{
	return tiles;
}


