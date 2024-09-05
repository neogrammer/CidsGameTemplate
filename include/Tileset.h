#pragma once
#include <Tileset.h>
#include <Tile.h>
#include <vector>
#include <memory>
#include <utility>
#include <string>
#include <Cfg.h>

class Tileset
{
	int cols{  };
	int rows{  };
	Cfg::Textures texType;
	std::vector<std::unique_ptr<Tile> > tiles;
public:
	Tileset();
	Tileset(const std::string& filename_);
	~Tileset();
	Tileset(const Tileset&) = delete;
	Tileset(Tileset&&) = delete;
	Tileset& operator=(Tileset&&) = delete;
	Tileset& operator=(const Tileset&) = delete;
	Tile copyTile(int tileIdx_);
	Cfg::Textures getTexType();




};