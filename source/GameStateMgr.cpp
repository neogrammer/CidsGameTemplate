#include <GameStateMgr.h>
#include <BeatStageState.h>
#include <DialogState.h>
#include <GameStartState.h>
#include <GameStateTransition.h>
#include <PlayerDeathState.h>
#include <PresentStageState.h>
#include <GameLoadState.h>
#include <GameSaveState.h>
#include <GameMenuState.h>
#include <GamePassword_InputState.h>
#include <PlayState.h>
#include <SplashState.h>
#include <StageSelectState.h>
#include <TitleState.h>
using namespace cid;



cid::GameStateMgr::GameStateMgr()
{
}

cid::GameStateMgr::~GameStateMgr()
{
}

void cid::GameStateMgr::setup()
{
	states.emplace(std::pair{ GameStateType::Splash, std::make_shared<SplashState>() });
	states.emplace(std::pair{ GameStateType::BeatStage , std::make_shared<BeatStageState>() });
	states.emplace(std::pair{ GameStateType::Dialog , std::make_shared<DialogState>() });
	states.emplace(std::pair{ GameStateType::GameStart , std::make_shared<GameStartState>() });
	states.emplace(std::pair{ GameStateType::StateTransition , std::make_shared<GameStateTransition>() });
	states.emplace(std::pair{ GameStateType::PlayerDeath , std::make_shared<PlayerDeathState>() });
	states.emplace(std::pair{ GameStateType::Load , std::make_shared<PresentStageState>() });
	states.emplace(std::pair{ GameStateType::Save , std::make_shared<GameLoadState>() });
	states.emplace(std::pair{ GameStateType::Menu , std::make_shared<GameSaveState>() });
	states.emplace(std::pair{ GameStateType::Password , std::make_shared<GameMenuState>() });
	states.emplace(std::pair{ GameStateType::Play , std::make_shared<GamePassword_InputState>() });
	states.emplace(std::pair{ GameStateType::StageSelect , std::make_shared<PlayState>() });
	states.emplace(std::pair{ GameStateType::Title , std::make_shared<TitleState>() });
	states.emplace(std::pair{ GameStateType::StageSelect, std::make_shared<StageSelectState>() });


	stateStack.push_back(states[GameStateType::Splash]);

}

void cid::GameStateMgr::render()
{
	for (auto& st : stateStack)
	{
		st.lock()->render();
	}
}

void cid::GameStateMgr::update()
{
	if (needsToSwitchState)
	{
		updateStack();
	}

	for (auto& st : stateStack)
	{
		st.lock()->update();
	}
}

void cid::GameStateMgr::input()
{
	for (auto& st : stateStack)
	{
		st.lock()->input();
	}
}

void cid::GameStateMgr::pushState(GameStateType type_)
{

	stateStack.push_back(states[type_]);
}

void cid::GameStateMgr::changeState(GameStateType type_)
{
	if (type_ == GameStateType::Count || type_ == GameStateType::NotSet)
	{
		needsToSwitchState = false;
		return;
	}
	nextState = type_;
	needsToSwitchState = true;
	popOffCurrent = true;
}

void cid::GameStateMgr::updateStack()
{
	if (needsToSwitchState)
	{
		if (nextState == GameStateType::Count || nextState == GameStateType::NotSet)
		{
			needsToSwitchState = false;
			return;
		}
		else
		{
			needsToSwitchState = false;
			if (popOffCurrent == true)
			{
				stateStack.pop_back();
				pushState(nextState);
				nextState = GameStateType::NotSet;
				return;
			}
			else
			{
				pushState(nextState);
				nextState = GameStateType::NotSet;
				return;
			}
		}
	}
}

void cid::GameStateMgr::popBack()
{
	stateStack.pop_back();

}


void cid::GameStateMgr::popFront()
{
	stateStack.pop_front();
}
