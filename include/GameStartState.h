#pragma once
#include <GameState.h>
#include <SFML/Graphics/Rect.hpp>


class GameStartState : public GameState
{
	sf::IntRect iRects[11] = { sf::IntRect{}, };
	float xPos{};
	float yPos{};
	int currRect = 0;
public:
	GameStartState();
	void input() override final;
	void update() override final;
	void render() override final;
};