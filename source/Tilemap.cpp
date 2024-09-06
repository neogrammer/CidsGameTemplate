#include "Tilemap.h"
#include <fstream>
#include <globals.h>
Tilemap::Tilemap()
	: tiles{}
	, zoneTileRanges{ {{},{}} }
	, tileset{}
{
}

Tilemap::~Tilemap()
{
}

//std::pair<sf::Vector2i, sf::Vector2i>& Tilemap::getZoneRange(int zoneNum_)
//{
//	return zoneTileRanges[zoneNum_];
//}

Cfg::Textures Tilemap::texType()
{
	return tileset.getTexType();
}

std::vector<std::shared_ptr<Tile>>& Tilemap::getTiles()
{
	return tiles;
}

void Tilemap::setupTiles(const std::string& filename_, const std::string& tsetData_)
{
	tileset.setup(tsetData_);

	std::ifstream file;
	file.open(filename_);

	if (!file.is_open() || !file.good())
	{
		return;
	}
	else
	{
		tiles.clear();

		int colsPerScreen, rowsPerScreen, totalRows, totalCols;
		file >> colsPerScreen >> rowsPerScreen >> totalCols >> totalRows;
		tiles.reserve(totalCols * totalRows);
		for (int y = 0; y < totalRows; y++)
		{
			for (int x = 0; x < totalCols; x++)
			{
				int num = y * totalCols + x;
				if (num >= tiles.capacity()) break;

				int tileSheetIdx;
				file >> tileSheetIdx;
				tiles.emplace_back(std::make_shared<Tile>(tileset.copyTile(tileSheetIdx).aabb));
				tiles.back()->aabb.pos = {(float)( x * tileset.getTileW()), float(y * tileset.getTileH()) };

			}
		}
		// read in file and use that number to copy a new tile from the tileset
		int i = 0;
		file.close();
	}
}

Cfg::Textures Tilemap::getTextureType()
{
	return tileset.getTexType();
}


std::pair<sf::Vector2i, sf::Vector2i>& Tilemap::getZoneRange(int zoneNum_)
{
	if (zoneTileRanges.find(zoneNum_) == zoneTileRanges.end())
	{
		return zoneTileRanges[zoneNum_];
			
	}
	else
	{
		return zoneTileRanges[zoneNum_];
		sf::Vector2i tl = zoneTileRanges[zoneNum_].first;
		sf::Vector2i br = zoneTileRanges[zoneNum_].second;
		int tilesX = br.x - tl.x;
		int tilesY = br.y - tl.y;
		//return { {tl.x,tl.y}, {tilesX, tilesY} };
	}
}
