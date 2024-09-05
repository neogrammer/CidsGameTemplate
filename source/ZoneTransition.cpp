#include "ZoneTransition.h"
#include <globals.h>
#include <memory>
#include <utility>

ZoneTransition::ZoneTransition()
	: GameState{}
	, fader{}
{
	type = GameStateType::StateTransition;
	this->fadeAmt = 0.f;
}

void ZoneTransition::destroySelf()
{
	if (gAcc.gameStateMgr->getTop().lock()->getType() == GameStateType::StateTransition)
		gAcc.gameStateMgr->popBack();
	return;
}

ZoneTransition::~ZoneTransition()
{
}

void ZoneTransition::input()
{
}


void ZoneTransition::setupAndStart(int zoneNumFrom_, int zoneNumTo_, std::shared_ptr<Zone> zoneFrom_, std::shared_ptr<Zone> zoneTo_)
{
	from = zoneNumFrom_;
	to = zoneNumTo_;
	fromZone = zoneFrom_;
	toZone = zoneTo_;

	fromBgSpr = &zoneFrom_->bgSpr;
	toBGSpr = &zoneTo_->bgSpr;
	if (zoneNumFrom_ < zoneNumTo_)
	{
		if ((zoneNumFrom_ / 3) == (zoneNumTo_ / 3))
		{
			// on same row
			fromFace = ZoneFace::East;
		}
		else
		{
			if ((zoneNumFrom_ % 3) == (zoneNumTo_ % 3))
			{
				// same column
				fromFace = ZoneFace::South;
			}
		}
	}
	else if (zoneNumFrom_ > zoneNumTo_)
	{
		if ((zoneNumFrom_ / 3) == (zoneNumTo_ / 3))
		{
			// on same row
			fromFace = ZoneFace::West;
		}
		else
		{
			if ((zoneNumFrom_ % 3) == (zoneNumTo_ % 3))
			{
				// same column
				fromFace = ZoneFace::North;
			}
		}
	}
	

	starting = true;
	fader.setFillColor(sf::Color(0, 0, 0, 0));
	fader.setSize({ 1600.f, 900.f });
	fader.setPosition(0.f, 0.f);
	fadeAmt = 0.f;
}

void ZoneTransition::update()
{
	if (running == false && starting == false)
	{
		destroySelf();
		return;
	}

	if (running)
	{
		fadeAmt -= 200.f * gTime;
		if (fadeAmt < 0.f)
		{
			fadeAmt = 0.0f;
			// stuff..
			running = false;
			starting = false;
		}
	

		// see below for starting
	}

	if (starting)
	{
	
		fadeAmt += 200.f * gTime;
		if (fadeAmt >= 255.f)
		{
			fadeAmt = 254.999999f;
			gAcc.stageMgr->setZone(to);
			// change player position now to the portal coming in through
			// stuff..
			running = true;
			starting = false;
		}


	
	}

	fader.setFillColor(sf::Color(0, 0, 0, (sf::Uint8)((int)fadeAmt)));
}

void ZoneTransition::render()
{
	gWnd.draw(fader);
}


void ZoneTransition::runToEnd()
{
}
