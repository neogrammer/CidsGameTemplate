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

		void setup(const std::string& tmapData_, const std::string& zoneData_);
		void input();
		void update();
		void render();
	};

}