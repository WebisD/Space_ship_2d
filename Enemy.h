#pragma once
#include "Ship.h"
#include <iostream>


#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy : public Ship
{
public:
	Enemy(class Game* game);
	void UpdateActor(float deltaTime) override;
private:
	void Enemy::SetInitialRandomPosition();
};
#endif