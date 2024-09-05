#pragma once
#include <map>;
#include <stack>
#include <memory>
#include <utility>
#include <GameState.h>
#include <game_state_types.h>
#include <deque>
class GameState;


namespace cid
{
	class GameStateMgr
	{
		std::map<GameStateType, std::shared_ptr<GameState> > states{};
		std::deque<std::weak_ptr<GameState> > stateStack{};

		GameStateType nextState{ GameStateType::NotSet };
		bool needsToSwitchState{ false };
		bool popOffCurrent{ true };
	public:
		GameStateMgr();
		~GameStateMgr();
		GameStateMgr(const GameStateMgr&) = delete;
		GameStateMgr& operator=(const GameStateMgr&) = delete;

		GameStateMgr(GameStateMgr&&) = delete;
		GameStateMgr& operator=(GameStateMgr&&) = delete;


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