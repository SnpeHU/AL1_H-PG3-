#include "weapen.h"

Weapen::Weapen()
{
	 
}

void Weapen::Fire(Vector2 _pos,Vector2 _toward)
{
	if (canFire)
	{
		canFire = false;

		Bullet* bullet = new Bullet();
		bullet->setPos(_pos.x,_pos.y);
		bullet->setToward(_toward);
		bulletList.push_back(bullet);

	}
}

void Weapen::updateBullets()
{
	bulletList.erase(std::remove_if(
		bulletList.begin(), bulletList.end(),
		[](const Bullet* bullet)
		{
			bool deletable = bullet->isCanRemove();
			if (deletable) delete bullet;
			return deletable;
		}),
		bulletList.end());

	for (Bullet* bullet : bulletList)
	{
		bullet->update();
	}
}

void Weapen::drawBullets()
{
	for (Bullet* bullet : bulletList)
	{
		bullet->draw();
	}
}
void Weapen::update()
{
	if (!canFire)
	{
		attackTimer++;
	}
	if (attackTimer >= fireCoolTime)
	{
		
		canFire = true;
		attackTimer = 0;
	}
}
void Weapen::switchBullet()
{
}


