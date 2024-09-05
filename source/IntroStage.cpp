#include "IntroStage.h"
#include <string>
#include <globals.h>

IntroStage::IntroStage(const std::string& tmapData_, const std::string& zoneData_, const std::string& tsetData_)
	: Stage{ tmapData_, zoneData_, tsetData_ }
{
}

IntroStage::~IntroStage()
{
}

void IntroStage::input()
{
}

void IntroStage::setup()
{
}

void IntroStage::update()
{
}

void IntroStage::render()
{
	gWnd.clear(sf::Color(47, 147, 247, 255));
}
