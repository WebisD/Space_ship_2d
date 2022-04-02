#pragma once
#include "Component.h"
#include "Bullet.h"
#include <vector>
#include <iostream>

#ifndef _BULLETCONTROLLERCOMPONENT_
#define _BULLETCONTROLLERCOMPONENT_

class BulletControllerComponent: public Component
{
public: 
	BulletControllerComponent(class Actor* owner);
	void Update(float deltaTime) override;
	void GenerateBullet();

private:
	std::vector<class Bullet*> bullets;
	
	bool checkBulletCollision(Bullet* bullet);

	Uint32 mLastShot = SDL_GetTicks();
};

#endif

