#include <Accessor.h>


using namespace cid;

Accessor::Accessor()
	: animMgr{},
	entityMgr{},
	fizzicksMgr{},
	gameStateMgr{},
	inputMgr{},
	scriptMgr{},
	stageMgr{}
{}

void Accessor::fill(AnimMgr& animMgr_,
	EntityMgr& entityMgr_,
	FizziksMgr& fizzicksMgr_,
	GameStateMgr& gameStateMgr_,
	InputMgr& inputMgr_,
	ScriptMgr& scriptMgr_,
	StageMgr& stageMgr_)
{
	animMgr = &animMgr_;
	entityMgr = &entityMgr_;
	fizzicksMgr = &fizzicksMgr_;
	gameStateMgr = &gameStateMgr_;
	inputMgr = &inputMgr_;
	scriptMgr = &scriptMgr_;
	stageMgr = &stageMgr_;
}