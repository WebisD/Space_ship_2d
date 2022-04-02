#include "Bullet.h"

Bullet::Bullet(Game* game, Vector2 position)
	:Actor(game)
	, mRightSpeed(100.f)
{
	this->SetPosition(position);

	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Bullet02.png")
	};
	asc->SetAnimTextures(anims);
}

void Bullet::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * mSpeedFactor * deltaTime;
	// Restrict position to left half of screen

	SetPosition(pos);
}
