#pragma once
#include <Stage.h>
#include <memory>
#include <utility>
#include <unordered_map>
class Stage;
namespace cid
{
	class StageMgr
	{
		std::unordered_map<std::string, std::shared_ptr<Stage> > stages{};
		std::shared_ptr<Stage> currStage{};

	public:

		void setup(const std::string& stageName_, const std::string & tmapData_, const std::string& zoneData_, const std::string& tsetData_);
		void input();
		void update();
		void render();
		std::shared_ptr<Stage> getStage(const std::string& stageName_);
		void setCurrStage(std::shared_ptr<Stage> newStage_);
		void setZone(int zoneNum_);

	};

}