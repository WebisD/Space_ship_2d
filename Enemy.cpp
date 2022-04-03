#include <cstdlib>
#include <math.h>
#include "Enemy.h"
#include "Utils.h"
#include "Game.h"
#include "AnimSpriteComponent.h"

Enemy::Enemy(Game* game) : Ship(game)
{
	SetInitialRandomPosition();
	
	mDownSpeed = .0f;
	mRightSpeed = -40.f;

	SetRotation(Math::Pi);
};


void Enemy::UpdateActor(float deltaTime)
{
	Vector2 pos = GetPosition();
	
	pos.x += GetRightSpeed() * deltaTime;
	pos.y += GetDownSpeed() * deltaTime;

	SetPosition(pos);
}


void Enemy::SetInitialRandomPosition()
{
	int gameWidth = GetGame()->GetGameWidth();
	int gameHeight = GetGame()->GetGameHeight();
	int offset = 200;

	int randX = Utils::RandNumber(gameWidth, gameWidth + offset);
	int randY = Utils::RandNumber(-GetMidHeight(), gameHeight + GetMidHeight());

	Vector2 randPosision = Vector2(randX, randY);
	SetPosition(randPosision);
}