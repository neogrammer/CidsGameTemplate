#include <StageMgr.h>
#include <IntroStage.h>
using namespace cid;

void cid::StageMgr::setup(const std::string& stageName_, const std::string& tmapData_, const std::string& zoneData_, const std::string& tsetData_)
{
	stages.clear();
	stages.reserve(stages.size() + 1);
	stages.emplace(std::pair{ stageName_, std::make_shared<IntroStage>(tmapData_, zoneData_, tsetData_)});

	if (currStage == nullptr)
		currStage = stages[stageName_];
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
