#include <Portal.h>
#include <assert.h>
#include <iostream>
void Portal::set(std::shared_ptr<Zone> otherSide_)
{
	if (otherSide.lock() != nullptr)
		std::cout << "Setting a smart pointer already set, losing the old one" << std::endl;
	otherSide.reset();
	otherSide = otherSide_;
}

std::shared_ptr<Zone> Portal::unset()
{
	auto p = otherSide.lock();
	otherSide.reset();
	if (p == nullptr) return nullptr;
	return p;
}
