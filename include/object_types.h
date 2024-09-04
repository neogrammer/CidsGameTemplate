#pragma once

namespace cid
{
	enum class ObjectType
	{
		Entity = 0,
		Script,
		Manager,
		Tile,
		Tileset,
		Tilemap,
		Zone,
		GameState,
		Stage,
		Accessor,
		Animation,
		AnimMap,
		Count,
		NotSet
	};
}