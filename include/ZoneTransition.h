#pragma once
#include <memory>
#include <utility>
#include <game_state_types.h>
#include <GameState.h>
#include <SFML/Graphics.hpp>
#include <Zone.h>
class ZoneTransition : public GameState
{
	int from{}, to{};
	std::shared_ptr<Zone> fromZone{}, toZone{};

	sf::Sprite* fromBgSpr;
	sf::Sprite* toBGSpr;

	sf::RectangleShape fader{};
	float fadeAmt{ 0.f };


	ZoneFace fromFace{ ZoneFace::NotSet };

	bool starting{false};
	bool running{ false };
public:
	ZoneTransition();
	void destroySelf();
	~ZoneTransition() override final;
	void input() override final;
	void update() override final;
	void render() override final;

	void setupAndStart(int zoneNumFrom_, int zoneNumTo_, std::shared_ptr<Zone> zoneFrom_, std::shared_ptr<Zone> zoneTo_);
	void runToEnd();

};
