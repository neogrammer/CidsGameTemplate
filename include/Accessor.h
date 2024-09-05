#pragma once

#include <AnimMgr.h>
#include <EntityMgr.h>
#include <FizziksMgr.h>
#include <GameStateMgr.h>
#include <InputMgr.h>
#include <ScriptMgr.h>
#include <StageMgr.h>

struct Accessor
{
	cid::AnimMgr*		animMgr;
	cid::EntityMgr*		entityMgr;
	cid::FizziksMgr*		fizzicksMgr;
	cid::GameStateMgr*	gameStateMgr;
	cid::InputMgr*		inputMgr;
	cid::ScriptMgr*		scriptMgr;
	cid::StageMgr*		stageMgr;
		
	Accessor();
	void fill(cid::AnimMgr& animMgr_,
		cid::EntityMgr& entityMgr_,
		cid::FizziksMgr& fizzicksMgr_,
		cid::GameStateMgr& gameStateMgr_,
		cid::InputMgr& inputMgr_,
		cid::ScriptMgr& scriptMgr_,
		cid::StageMgr& stageMgr_);



};
