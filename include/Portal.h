#pragma once
#include <memory>
#include <utility>
class Zone;

struct Portal
{
	std::weak_ptr<Zone> otherSide{};

	void set(std::shared_ptr<Zone> otherSide_);
	std::shared_ptr<Zone> unset();

};