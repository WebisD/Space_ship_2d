#include "Enemy.h"
#include "Utils.h"
#include "Game.h"
#include <cstdlib>
#include "AnimSpriteComponent.h"

Enemy::Enemy(Game* game) :
	Actor(game),
	mLeftSpeed(0.0f),
	mDownSpeed(0.0f)
{

	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png"),
	};
	asc->SetAnimTextures(anims);



};


void Enemy::UpdateActor(float deltaTime)
{

}


void Enemy::SetInitialRandomPosition()
{
	int gameWidth = GetGame()->GetGameWidth();
	int gameHeight = GetGame()->GetGameHeight();
	int offset = 200;

	int randX = Utils::RandNumber(gameWidth, gameWidth + offset);
	int randY = Utils::RandNumber(-Ge, gameHeight + )

		Vector2
		SetPosition
}