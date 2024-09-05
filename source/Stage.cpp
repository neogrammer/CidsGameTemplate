#include "Stage.h"
#include <fstream>
#include <Portal.h>

Stage::Stage(const std::string& tmapData_, const std::string& zoneData_, const std::string& tsetData_)
	: tmap{ std::make_unique<Tilemap>() }
{
	
	tmap->setupTiles(tmapData_, tsetData_);
	int count = 0;
	std::ifstream file;
	file.open(zoneData_);
	int numZones;
	file >> numZones;
	int zoneW, zoneH;
	file >> zoneW >> zoneH;
	//int zoneWidthPxl, zoneHeightPxl;
	while (count < numZones)
	{
		std::shared_ptr<Zone> aZone = std::make_shared<Zone>();
		zones.push_back(aZone);
		auto col = count % 32; auto row = count / 32;
		zones.back()->setup(count, { {count * 32, row * 18}, {col * 32 + zoneW, row * 18 + zoneH} }, tmap->getTiles(), zoneW, Cfg::textures.get((int)tmap->texType()), { {count * 32, row * 18}, {col * 32 + zoneW, row * 18 + zoneH} }, nullptr,nullptr,nullptr,nullptr);
		zones.back()->portals[int(ZoneFace::North)] = Portal{};
		zones.back()->portals[int(ZoneFace::South)] = Portal{};
		zones.back()->portals[int(ZoneFace::East)] = Portal{};
		zones.back()->portals[int(ZoneFace::West)] = Portal{};

		count++;
	}

	

	for (int i = 0; i < numZones; i++)
	{
		for (int j = 0; j < zones[i]->portals.size(); j++)
		{
			bool topRow = false;
			bool bottomRow = false;
			bool rightCol = false;

			bool leftCol = false;
			if (i < zoneW)
			{
				topRow = true;
			}
			if (i >= numZones - zoneW)
			{
				bottomRow = true;
			}
			if (j % zoneW == 0)
			{
				leftCol = true;
			}
			if ((j % zoneW) == (zoneW - 1))
			{
				rightCol = true;
			}
			int n{ -1 }, s{ -1 }, e{ -1 }, w{ -1 };
			if (!leftCol && !rightCol && !topRow && !bottomRow)
			{
				
				zones[i]->portals.at((int)ZoneFace::North).set(zones[i - zoneW]);
				zones[i]->portals.at((int)ZoneFace::South).set(zones[i + zoneW]);
				zones[i]->portals.at((int)ZoneFace::East).set(zones[i + 1]);
				zones[i]->portals.at((int)ZoneFace::West).set(zones[i-1]);
			}
			else
			{
				if (leftCol && topRow)
				{
				
					zones[i]->portals.at((int)ZoneFace::South).set(zones[i + zoneW]);
					zones[i]->portals.at((int)ZoneFace::East).set(zones[i + 1]);
					
				}
				else if (leftCol && bottomRow)
				{
					zones[i]->portals.at((int)ZoneFace::North).set(zones[i - zoneW]);
					zones[i]->portals.at((int)ZoneFace::East).set(zones[i + 1]);
					
				}
				else if (topRow && rightCol)
				{ 
					
					zones[i]->portals.at((int)ZoneFace::South).set(zones[i + zoneW]);
					
					zones[i]->portals.at((int)ZoneFace::West).set(zones[i - 1]);
				}
				else if (bottomRow && rightCol)
				{ 
					zones[i]->portals.at((int)ZoneFace::North).set(zones[i - zoneW]);
					zones[i]->portals.at((int)ZoneFace::West).set(zones[i - 1]);
				}
				else if (leftCol)
				{
					zones[i]->portals.at((int)ZoneFace::North).set(zones[i - zoneW]);
					zones[i]->portals.at((int)ZoneFace::South).set(zones[i + zoneW]);
					zones[i]->portals.at((int)ZoneFace::East).set(zones[i + 1]);

				}
				else if (bottomRow)
				{
					zones[i]->portals.at((int)ZoneFace::North).set(zones[i - zoneW]);
					
					zones[i]->portals.at((int)ZoneFace::East).set(zones[i + 1]);
					zones[i]->portals.at((int)ZoneFace::West).set(zones[i - 1]);
				}
				else if (topRow)
				{

					zones[i]->portals.at((int)ZoneFace::South).set(zones[i + zoneW]);
					zones[i]->portals.at((int)ZoneFace::East).set(zones[i + 1]);
					zones[i]->portals.at((int)ZoneFace::West).set(zones[i - 1]);
				}
				else if (rightCol)
				{
					zones[i]->portals.at((int)ZoneFace::North).set(zones[i - zoneW]);
					zones[i]->portals.at((int)ZoneFace::South).set(zones[i + zoneW]);
					zones[i]->portals.at((int)ZoneFace::West).set(zones[i - 1]);
				}
			}
		}
	}
}

Stage::~Stage()
{
}
//
//void Stage::setZone(int zoneNum_, std::pair<sf::Vector2i, sf::Vector2i> tileCorners_, std::vector<std::shared_ptr<Tile>>& tiles_, int cols_, sf::Texture& tex_, sf::IntRect iRect_, std::shared_ptr<Zone> north_, std::shared_ptr<Zone> south_, std::shared_ptr<Zone> east_, std::shared_ptr<Zone> west_)
//{
//	zones.emplace_back(std::make_shared<Zone>());
//	zones.back()->setup(zoneNum_, tileCorners_, tiles_, cols_, tex_, iRect_, north_, south_, east_, west_);
//}

