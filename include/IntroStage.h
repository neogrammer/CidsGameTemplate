#pragma once
#include <Stage.h>

class IntroStage : public Stage
{
public:
	int zoneAdj{ 0 };
public:
	IntroStage() = delete;
	IntroStage(const std::string& tmapData_, const std::string& zoneData_, const std::string& tsetData_);
	~IntroStage() override final;
	void input() override final;
	void setup() override final;
	void update() override final;
	void render() override final;
};
