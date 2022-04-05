#pragma once
#include "Actor.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "Math.h"

#ifndef _BULLET_
#define _BULLET_

class Bullet: public Actor
{
public:
	Bullet(class Game* game, Vector2 position);
	void UpdateActor(float deltaTime) override;
	float GetRightSpeed() const { return mRightSpeed; }
private:
	float mRightSpeed = 5;
	float mSpeedFactor = 1;
};

#endif

