#include "BulletControllerComponent.h"

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
			bullets.pop_back();
			std::cout << bullet << " " << currIdx << "\n";
			delete bullet;
		}
		else {
			bullet->Update(deltaTime);
		}

		currIdx++;
	}
}

bool BulletControllerComponent::checkBulletCollision(Bullet* bullet) 
{
	if (bullet->GetPosition().x >= 800.f)
	{
		std::cout << "FORA DA TELA PORRA\n";
		return true;
	}

	return false;
}

void BulletControllerComponent::GenerateBullet()
{
	if (mLastShot <= SDL_GetTicks() + 200) {
		bullets.push_back(new Bullet(mOwner->GetGame(), mOwner->GetPosition()));
		mLastShot += SDL_GetTicks();
	}
}