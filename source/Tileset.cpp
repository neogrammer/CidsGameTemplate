#include "Tileset.h"
#include <fstream>
Tileset::Tileset()
	: texType{Cfg::Textures::NotSet}
{
}

Tileset::Tileset(const std::string& filename_)
	: texType{ Cfg::Textures::NotSet }
{
	std::ifstream file;
	file.open(filename_);

	if (!file.good() || !file.is_open())
		return;
	else
	{
		std::string texName;
		file >> texName;
		texType = Cfg::stringToTex[texName];
		// read in tileset data
	}
}

Tileset::~Tileset()
{
}

Tile Tileset::copyTile(int tileIdx_)
{
	return *tiles.at(tileIdx_);
}

Cfg::Textures Tileset::getTexType()
{
	return texType;
}

void Tileset::setup(const std::string& tsetData_)
{
	std::ifstream file;
	file.open(tsetData_);

	int numTiles{ 100 };
	int pitch{ 10 }; 
	int tw{ 50 };
	int th{ 50 };
	//file >> numTiles >> pitch >> tw >> th;
	rows = numTiles / pitch;
	cols = pitch;
	tiles.clear();
	tiles.reserve(rows * cols);
	for (int y = 0; y < numTiles / pitch; y++)
	{
		for (int x = 0; x < pitch; x++)
		{
			if (y * pitch + x >= numTiles) break;

			AABB tmp(true, { tw,th }, { x * tw, y * th }, { 0.f,0.f }, { 0,0 }, { (float)tw,(float)th });
			tiles.emplace_back(std::make_unique<Tile>(tmp));
			int solid_;
			file >> solid_;
			if (solid_ == 1)
			{
				tiles.back()->setSolid(true);
			}
			else
			{
				tiles.back()->setSolid(false);
			}
		}
	}
	int i = 0;
}
