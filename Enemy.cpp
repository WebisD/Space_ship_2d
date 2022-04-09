#include <cstdlib>
#include <math.h>
#include "Enemy.h"
#include "Utils.h"
#include "Game.h"
#include "Ship.h"
#include "AnimSpriteComponent.h"
#include <iostream>

Enemy::Enemy(Game* game) : Ship(game)
{
	SetInitialRandomPosition();
	
	mDownSpeed = .0f;
	mRightSpeed = -40.f;

	SetRotation(Math::Pi);
};

void Enemy::RemoveEnemyFromGame()
{
	vector<Enemy*>* enemies = GetGame()->GetEnemies();

	int it = 0;
	for (auto& enemy : *enemies)
	{
		if (this == enemy) {
			enemies->erase(enemies->begin() + it);
			return;
		}
		it++;
	}
}

void Enemy::SetRightSpeed(float newSpeed)
{
	this->mRightSpeed *= newSpeed;
}


void Enemy::UpdateActor(float deltaTime)
{

	if (mHit) {
		this->GetGame()->IncrementScore();
		RemoveEnemyFromGame();
		delete this;
		return;
	}

	Vector2 pos = GetPosition();
	
	pos.x += GetRightSpeed() * deltaTime;
	pos.y += GetDownSpeed() * deltaTime;

	SetPosition(pos);

	const bool isOutOfWindow = pos.x - GetMidWidth() < -GetMidWidth() * 2;
	if (isOutOfWindow)
	{
		RemoveEnemyFromGame();
		delete this;
	}
}


void Enemy::SetInitialRandomPosition()
{
	int gameWidth = GetGame()->GetGameWidth();
	int gameHeight = GetGame()->GetGameHeight();
	int offset = 200;

	int randX = Utils::RandNumberX();
	int randY = Utils::RandNumberY();

	Vector2 randPosision = Vector2(randX, randY);
	SetPosition(randPosision);
}