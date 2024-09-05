#pragma once
#include <SFML/System/Vector2.hpp>

struct AABB
{
	bool attachedToTileset{ false };

	sf::Vector2i texRectDims{ 0,0 };
	sf::Vector2i texPos{ 0,0 };
	sf::Vector2f pos{ 0, 0 };
	sf::Vector2i texOffset{ 0,0 };
	sf::Vector2f dims{ 0.f,0.f };

	AABB(bool attachedToTileset_ = false, sf::Vector2i texRectDims_ = { 0,0 }
		, sf::Vector2i texPos_ = { 0,0 }
		, sf::Vector2f pos_ = { 0, 0 }
		, sf::Vector2i texOffset_ = { 0,0 }
		, sf::Vector2f dims_ = { 0.f,0.f });

	~AABB();
	AABB(const AABB&) = default;
	AABB(AABB&&) = delete;

	AABB& operator=(const AABB&) = default;
	AABB& operator=( AABB&&) = delete;

};