#include "AABB.h"

AABB::AABB(bool attachedToTileset_, sf::Vector2i texRectDims_, sf::Vector2i texPos_, sf::Vector2f pos_, sf::Vector2i texOffset_, sf::Vector2f dims_)
	: attachedToTileset{ attachedToTileset_ }, texRectDims{ texRectDims_ }, texPos{ texPos_ }, texOffset{ texOffset_ }, dims{ dims_ }
{}

AABB::~AABB()
{
}
