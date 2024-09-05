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
