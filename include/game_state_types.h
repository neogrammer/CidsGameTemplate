#pragma once

enum class GameStateType
{
	Splash,
	Load,
	Save,
	Menu,
	Password,
	Play,
	StageSelect,
	Title,
	BeatStage,
	Dialog,
	GameStart,
	StateTransition,
	PlayerDeath,
	PresentStage,
	Count,
	NotSet
};