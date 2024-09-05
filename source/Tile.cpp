#include "Tile.h"

bool Tile::isSolid()
{
	return solid;
}

void Tile::setSolid(bool c_)
{
	solid = c_;
}

Tile::Tile(const AABB& aabb_)
	: aabb{aabb_}
{
}
