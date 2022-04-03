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
	void SetShotInterval(Uint32 shotInterval);

private:
	std::vector<class Bullet*> bullets;
	std::vector<std::pair<int, Bullet*>> bulletsToDelete;
	
	bool checkBulletCollision(Bullet* bullet);

	Uint32 mLastShot = 0;
	Uint32 mShotInterval = 500;
};

#endif

