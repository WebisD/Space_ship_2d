#include "BulletControllerComponent.h"
#include "Enemy.h"

BulletControllerComponent::BulletControllerComponent(Actor* owner)
	:Component(owner)
{
}

void BulletControllerComponent::Update(float deltaTime)
{
	int currIdx = 0;

	for (auto& bullet : bullets)
	{
		if (checkBulletCollision(bullet))
		{
			bulletsToDelete.push_back(std::make_pair(currIdx, bullet));
		}
		else {
			bullet->Update(deltaTime);
		}

		currIdx++;
	}

	int size = bulletsToDelete.size();
	
	for (int i = 0; i < size; i++) {
		int idx = bulletsToDelete[i].first;
		bullets.erase(bullets.begin() + idx);
		delete bulletsToDelete[i].second;
	}

	bulletsToDelete.clear();
}

bool BulletControllerComponent::checkBulletCollision(Bullet* bullet) 
{
	if (bullet->GetPosition().x >= mOwner->GetGame()->GetWindowWidth())
	{
		return true;
	}

	for (class Enemy* enemy : mOwner->GetGame()->GetEnemies())
	{
		if (
			bullet->GetPosition().x > enemy->GetPosition().x - enemy->GetWidth()
			&& bullet->GetPosition().y <= enemy->GetPosition().y + enemy->GetMidHeight() && bullet->GetPosition().y >= enemy->GetPosition().y - enemy->GetMidHeight()
		) {
			printf("ACERTOU!\n");
			enemy->SetHit(true);
			return true;
		}
	}

	return false;
}

void BulletControllerComponent::GenerateBullet()
{
	if (SDL_GetTicks() > mLastShot + mShotInterval) {
		mLastShot = SDL_GetTicks();
		bullets.push_back(new Bullet(mOwner->GetGame(), mOwner->GetPosition()));
	}
}

void BulletControllerComponent::SetShotInterval(Uint32 shotInterval) {
	mShotInterval = shotInterval;
}