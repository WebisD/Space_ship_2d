// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Ship.h"

Ship::Ship(Game* game)
	:Actor(game)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
{
	// Create an animated sprite component
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png"),
	};
	asc->SetAnimTextures(anims);

	this->bcc = new BulletControllerComponent(this);

	mWidth = 64.f;
	mHeight = 29.;
}

void Ship::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;
	// Restrict position to left half of screen
	if (pos.x - GetMidWidth() < 0)
	{
		pos.x = GetMidWidth();
	}
	else if (pos.x + GetMidWidth() > GetGame()->GetGameWidth())
	{
		pos.x = GetGame()->GetGameWidth() - GetMidWidth();
	}
	if (pos.y - GetMidHeight() < 0.0f)
	{
		pos.y = GetMidHeight();
	}
	else if (pos.y + GetMidHeight() > GetGame()->GetGameHeight())
	{
		pos.y = GetGame()->GetGameHeight() - GetMidHeight();
	}
	SetPosition(pos);
}

void Ship::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
	}
	
	if (state[SDL_SCANCODE_SPACE])
	{
		//BulletControllerComponent* bcc = (BulletControllerComponent*) GetComponent(new BulletControllerComponent(this));
		this->bcc->GenerateBullet();
	}
}
