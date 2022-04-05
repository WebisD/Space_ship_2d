// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
#include "BulletControllerComponent.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

#ifndef _SHIP_H_
#define _SHIP_H_

class Ship : public Actor
{
public:
	Ship(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ProcessKeyboard(const uint8_t* state);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }
protected:
	float mRightSpeed;
	float mDownSpeed;
	BulletControllerComponent* bcc = nullptr;
};

#endif