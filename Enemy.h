#pragma once
#include "Actor.h"


#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy : public Actor
{
public:
	Enemy(class Game* game);
	void UpdateActor(float deltaTime) override;
	float GetLeftSpeed() const { return mLeftSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }
private:
	float mLeftSpeed;
	float mDownSpeed;
	void Enemy::SetInitialRandomPosition();
};


#endif