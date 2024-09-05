#include <StageMgr.h>
#include <IntroStage.h>
using namespace cid;

void cid::StageMgr::setup(const std::string& tmapData_, const std::string& zoneData_)
{
	stages.clear();
	stages.reserve(1);
	stages.emplace(std::pair{ "IntroStage", std::make_shared<IntroStage>(tmapData_, zoneData_) });

	currStage = stages["IntroStage"];
}

void cid::StageMgr::input()
{
	currStage->input();
}

void cid::StageMgr::update()
{
	currStage->update();
}

void cid::StageMgr::render()
{
	currStage->render();
}
