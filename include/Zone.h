#pragma once
#include <array>
#include <memory>
#include <utility>
#include <vector>
#include <Cfg.h>
#include <SFML/Graphics/Rect.hpp>


#include <Portal.h>
struct Tile;
enum class ZoneFace
{
	North,
	West,
	East,
	South,
	Count,
	NotSet
};

class Zone
{

public:

	std::array <Portal, 4 > portals = { Portal{}, Portal{}, Portal{}, Portal{} };
	int zoneID{ -1 };

	sf::Sprite bgSpr{};
	sf::Sprite bgSpr2{};
	sf::Vector2i topLeftTile{};
	sf::Vector2i bottomRightTile{};
	std::vector<std::weak_ptr<Tile> > tiles{};

public:
	Zone() = default;
	virtual ~Zone();

	// tile corners is a pair of (col, row) pairs for the top left tile and bottom right
	void setup(int zoneNum, std::pair<sf::Vector2i, sf::Vector2i> tileCorners, std::vector<std::shared_ptr<Tile> >& tiles_, int cols_, sf::Texture& tex, sf::IntRect iRect_ = { {0,0},{0,0} }, std::shared_ptr<Zone> north_ = nullptr, std::shared_ptr<Zone> south_ = nullptr, std::shared_ptr<Zone> east_ = nullptr, std::shared_ptr<Zone> west_ = nullptr);
	void input();
	void update();
	void render();
	std::array<Portal, 4>& getPortals();
	std::vector<std::weak_ptr<Tile> >& getTiles();

};