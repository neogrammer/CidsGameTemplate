#pragma once
#include <Tileset.h>
#include <vector>
#include <memory>
#include <utility>
#include <unordered_map>
#include <Zone.h>
#include <SFML/Graphics/Rect.hpp>
#include <Zone.h>
#include <string>
class Tilemap
{
	int cols{ };
	int rows{ };

	std::vector<std::shared_ptr<Tile> > tiles;
	std::unordered_map<int, std::pair<sf::Vector2i, sf::Vector2i> > zoneTileRanges; // tiles
	Tileset tileset{};
	
public:
	Tilemap();
	~Tilemap();
	Tilemap(const Tilemap&) = delete;
	Tilemap(Tilemap&&) = delete;
	Tilemap& operator=(const Tilemap&) = delete;
	Tilemap& operator=(Tilemap&&) = delete;
	std::pair<sf::Vector2i,sf::Vector2i>& getZoneRange(int zoneNum_);
	void setZone(int zoneNum_, std::shared_ptr<Zone> zone_);
	Cfg::Textures texType();
	std::vector<std::shared_ptr<Tile> >& getTiles();
	void setupTiles(const std::string& filename_, const std::string& tsetData_);

};