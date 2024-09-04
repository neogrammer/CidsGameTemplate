#pragma once
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

class Game
{
	void input();
	void update();
	void updateLate();
	void render();

public:

	Game();
	~Game();
	void* run();
};