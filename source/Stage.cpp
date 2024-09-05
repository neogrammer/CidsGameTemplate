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
		auto col = count % 3; 
		auto row = count / 3;
		zones.back()->setup(count, { {(count % 3) * zoneW, (count / 3) * zoneH}, {(count % 3) * zoneW + zoneW ,  (count / 3) * zoneH + zoneH } }, tmap->getTiles(), zoneW * 3, Cfg::textures.get((int)tmap->texType()), { {0,0},{50,50} }, nullptr, nullptr, nullptr, nullptr);

		count++;
	}

	

	for (int i = 0; i < numZones; i++)
	{
		zones[i]->bgSpr = {};
		zones[i]->bgSpr.setTexture(Cfg::textures.get((int)Cfg::Textures::SpaceBG));
		// set texture rect of big background here	
		bool topRow = false;
			bool bottomRow = false;
			bool rightCol = false;

			bool leftCol = false;
			if (i < 3)
			{
				topRow = true;
			}
			if (i >= numZones - 3)
			{
				bottomRow = true;
			}
			if (i % 3 == 0)
			{
				leftCol = true;
			}
			if ((i % 3) == (3 - 1))
			{
				rightCol = true;
			}
			int n{ -1 }, s{ -1 }, e{ -1 }, w{ -1 };
			if (!leftCol && !rightCol && !topRow && !bottomRow)
			{
				
				zones[i]->getPortals()[(int)ZoneFace::North].set(zones[(i % 3) + 3 * (i / 3) - 3]);
				zones[i]->getPortals()[(int)ZoneFace::South].set(zones[(i % 3) + 3 * (i / 3) + 3]);
				zones[i]->getPortals()[(int)ZoneFace::East].set(zones[(i % 3) + 3 * (i / 3) + 1]);
				zones[i]->getPortals()[(int)ZoneFace::West].set(zones[(i % 3) + 3 * (i / 3) - 1]);

			}
			else
			{
				if (leftCol && topRow)
				{

					zones[i]->getPortals()[(int)ZoneFace::South].set(zones[(i % 3) + 3 * (i / 3) + 3]);
					zones[i]->getPortals()[(int)ZoneFace::East].set(zones[(i % 3) + 3 * (i / 3) + 1]);
					
				}
				else if (leftCol && bottomRow)
				{
					zones[i]->getPortals()[(int)ZoneFace::North].set(zones[(i % 3) + 3 * (i / 3) - 3]);

					zones[i]->getPortals()[(int)ZoneFace::East].set(zones[(i % 3) + 3 * (i / 3) + 1]);
					
				}
				else if (topRow && rightCol)
				{ 
					
					zones[i]->getPortals()[(int)ZoneFace::South].set(zones[(i % 3) + 3 * (i / 3) + 3]);

					zones[i]->getPortals()[(int)ZoneFace::West].set(zones[(i % 3) + 3 * (i / 3) - 1]);

				}
				else if (bottomRow && rightCol)
				{ 
					zones[i]->getPortals()[(int)ZoneFace::North].set(zones[(i % 3) + 3 * (i / 3) - 3]);

					zones[i]->getPortals()[(int)ZoneFace::West].set(zones[(i % 3) + 3 * (i / 3) - 1]);

				}
				else if (leftCol)
				{
					zones[i]->getPortals()[(int)ZoneFace::North].set(zones[(i % 3) + 3 * (i / 3) - 3]);
					zones[i]->getPortals()[(int)ZoneFace::South].set(zones[(i % 3) + 3 * (i / 3) + 3]);
					zones[i]->getPortals()[(int)ZoneFace::East].set(zones[(i % 3) + 3 * (i / 3) + 1]);
					

				}
				else if (bottomRow)
				{
					zones[i]->getPortals()[(int)ZoneFace::North].set(zones[(i % 3) + 3 * (i / 3) - 3]);

					zones[i]->getPortals()[(int)ZoneFace::East].set(zones[(i % 3) + 3 * (i / 3) + 1]);
					zones[i]->getPortals()[(int)ZoneFace::West].set(zones[(i % 3) + 3 * (i / 3) - 1]);

				}
				else if (topRow)
				{
					zones[i]->getPortals()[(int)ZoneFace::South].set(zones[(i % 3) + 3 * (i / 3) + 3]);
					zones[i]->getPortals()[(int)ZoneFace::East].set(zones[(i % 3) + 3 * (i / 3) + 1]);
					zones[i]->getPortals()[(int)ZoneFace::West].set(zones[(i % 3) + 3 * (i / 3) - 1]);

				}
				else if (rightCol)
				{
					zones[i]->getPortals()[(int)ZoneFace::North].set(zones[(i % 3) + 3 * (i / 3) - 3]);
					zones[i]->getPortals()[(int)ZoneFace::South].set(zones[(i % 3) + 3 * (i / 3) + 3]);
					zones[i]->getPortals()[(int)ZoneFace::West].set(zones[(i % 3) + 3 * (i / 3) - 1]);
				}
			}
		
	}
}

Stage::~Stage()
{
}
Cfg::Textures Stage::getTSetTex()
{
	return tmap->getTextureType();
}
std::shared_ptr<Zone> Stage::getZone()
{
	return zones.at(currZoneIdx);
}

std::shared_ptr<Zone> Stage::getZone(int idx)
{
	return zones.at(idx);
}
//
//void Stage::setZone(int zoneNum_, std::pair<sf::Vector2i, sf::Vector2i> tileCorners_, std::vector<std::shared_ptr<Tile>>& tiles_, int cols_, sf::Texture& tex_, sf::IntRect iRect_, std::shared_ptr<Zone> north_, std::shared_ptr<Zone> south_, std::shared_ptr<Zone> east_, std::shared_ptr<Zone> west_)
//{
//	zones.emplace_back(std::make_shared<Zone>());
//	zones.back()->setup(zoneNum_, tileCorners_, tiles_, cols_, tex_, iRect_, north_, south_, east_, west_);
//}

