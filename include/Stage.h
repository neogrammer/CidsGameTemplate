#pragma once
#include <Tilemap.h>
#include <memory>
#include <utility>
#include <vector>
#include <Zone.h>
#include <string>
struct Portal;

class Stage
{
protected:
	std::unique_ptr<Tilemap> tmap;
	std::vector<std::shared_ptr<Zone> > zones{};
	int currZoneIdx{ 0 };

	// put player here

public:
	Stage() = delete;

	Stage(const std::string& tmapData_, const std::string& zoneData_, const std::string& tsetData_);
	virtual ~Stage();
	
	virtual void setup() = 0;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	Cfg::Textures getTSetTex();
	//void setZone(int zoneNum_, std::pair<sf::Vector2i, sf::Vector2i> tileCorners_, std::vector<std::shared_ptr<Tile> >& tiles_, int cols_, sf::Texture& tex_, sf::IntRect iRect_ = { {0,0},{0,0} }, std::shared_ptr<Zone> north_ = nullptr, std::shared_ptr<Zone> south_ = nullptr, std::shared_ptr<Zone> east_ = nullptr, std::shared_ptr<Zone> west_ = nullptr);
	std::shared_ptr<Zone> getZone();
	std::shared_ptr<Zone> getZone(int idx);
	void setCurrZone(int idx);
};