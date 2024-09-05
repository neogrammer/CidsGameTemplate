#pragma once
#include <map>;
#include <stack>
#include <memory>
#include <utility>
#include <GameState.h>
#include <game_state_types.h>

#include <deque>
#include <string>
class GameState;
class Stage;

namespace cid
{
	class GameStateMgr
	{
		std::map<GameStateType, std::shared_ptr<GameState> > states{};
		std::deque<std::weak_ptr<GameState> > stateStack{};

		GameStateType nextState{ GameStateType::NotSet };
		std::shared_ptr<Stage> currStage{};
		bool needsToSwitchState{ false };
		bool popOffCurrent{ true };
	public:

		int zoneBeforeChange{ 0 };
	public:
		GameStateMgr();
		~GameStateMgr();
		GameStateMgr(const GameStateMgr&) = delete;
		GameStateMgr& operator=(const GameStateMgr&) = delete;

		GameStateMgr(GameStateMgr&&) = delete;
		GameStateMgr& operator=(GameStateMgr&&) = delete;
		void setupState(GameStateType type_, const std::string& stageName_);
		GameStateType getCurrentStateType();
		std::weak_ptr<GameState>& getTop();
		void setup();
		void render();
		void update();
		void input();
		void pushState(GameStateType type_);
		void changeState(GameStateType type_);
		void updateStack();

		void popBack();
		void popFront();


	};
}