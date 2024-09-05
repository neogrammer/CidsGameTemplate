#pragma once
#include <SFML/System/Vector2.hpp>
#include <AABB.h>
struct Tile
{
	bool solid{ false };
	AABB aabb{};
public:
	bool isSolid();
	void setSolid(bool c_);

	Tile() = default;
	Tile(const AABB& aabb_);
	~Tile() = default;
	Tile(const Tile&) = default;
	Tile(Tile&&) = delete;
	Tile& operator=(const Tile&) = default;
	Tile& operator=(Tile&&) = delete;


};
