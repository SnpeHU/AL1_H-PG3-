#include "bullet.h"
extern const int windowRight;
extern const int windowbottom;

void Bullet::update()
{
	if (checkPos())
	{
		canRemove = true;
	}
	pos.x += velocity * toward.x;
	pos.y += velocity * toward.y;


}

void Bullet::draw()
{
	//Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y), size,size, 0.0f, 0xFF69B4FF, kFillModeWireFrame);
	Novice::DrawSprite(static_cast<int>(pos.x - 16) , static_cast<int>(pos.y - 16), bulletPic, 0.6f, 0.6f, 0.0f, WHITE);
}


bool Bullet::checkPos()
{
	if (pos.x < 0 || pos.x > windowRight || pos.y < 0 || pos.y > windowbottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Bullet::checkEnemyCollision(Vector2 _enemyPos, int _size)
{
	float dirX = _enemyPos.x - pos.x;
	float dirY = _enemyPos.y - pos.y;
	float toEnemyDir = sqrtf(dirX * dirX + dirY * dirY);
	if (toEnemyDir < _size +size)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Bullet::setToward(Vector2 _toward)
{
	toward = _toward;
}


void Bullet::setValid(bool _isValid)
{
	isValid = _isValid;
}

bool Bullet::getValid()
{
	return isValid;
}


void Bullet::setCanRemove(bool _isCanRemove)
{
	canRemove = _isCanRemove;
}
bool Bullet::isCanRemove() const
{
	return canRemove;
}


void Bullet::setPos(float _x, float _y)
{
	pos.x = _x;
	pos.y = _y;
}

const Vector2& Bullet::getPos()
{
	return pos;
}


void Bullet::setDamage(int _damage)
{
	damage = _damage;
}

int Bullet::getDamage()
{
	return damage;
}

//const Vector2& Bullet::getSize()
//{
//	return size;
//}

void Bullet::setVelocity(float _velocity)
{
	velocity = _velocity;
}

//void Bullet::setCallback(std::function<void> _callback)
//{
//	this->callback = _callback;
//}


