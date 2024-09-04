#include <globals.h>

#include <Err.h>
#include <Cfg.h>

#include <AnimMgr.h>
#include <EntityMgr.h>
#include <FizziksMgr.h>
#include <GameStateMgr.h>
#include <InputMgr.h>
#include <ScriptMgr.h>
#include <StageMgr.h>
#include <Game.h>



using namespace cid;




int main()
{
	Cfg::Initialize();

	AnimMgr animMgr = {};
	EntityMgr entityMgr = {};
	FizziksMgr fizziksMgr = {};
	GameStateMgr gameStateMgr = {};
	InputMgr inputMgr = {};
	ScriptMgr scriptMgr = {};
	StageMgr stageMgr = {};
	::gAcc.fill(animMgr, entityMgr, fizziksMgr, gameStateMgr, inputMgr, scriptMgr, stageMgr);
	Game demo;
	void* err = demo.run();
	if (err != nullptr)
	{
		Err e{ "Error:", ObjectType::Entity, err, OffendingParameterBundleType::TransformParams };
		e.render();
		return -1;
	}
	return 0;
}