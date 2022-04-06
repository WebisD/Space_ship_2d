#pragma once
#include <iostream>
#include "Ship.h"

#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy : public Ship
{
public:
	Enemy(class Game* game);
	void UpdateActor(float deltaTime) override;
	void SetHit(bool hit) { mHit = hit; }
private:
	void SetInitialRandomPosition();
	bool mHit = false;
};
#endif