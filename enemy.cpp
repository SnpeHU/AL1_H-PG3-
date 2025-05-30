#include "enemy.h"
Enemy::Enemy()
{
	SpawnDir spawnDIr = (SpawnDir)(rand() % 4);
	switch (spawnDIr)
	{
	case SpawnDir::UP:
		pos.y = 0.0f;
		pos.x = static_cast<float>(rand() % windowRight);
		break;
	case SpawnDir::DOWN:
		pos.y = static_cast<float>(windowbottom);
		pos.x = static_cast<float>(rand() % windowRight);
		break;
	case SpawnDir::RIGHT:
		pos.x = static_cast<float>(windowRight);
		pos.y = static_cast<float>(rand() % windowbottom);
		break;
	case SpawnDir::LEFT:
		pos.x = 0.0f;
		pos.y = static_cast<float>(rand() % windowbottom);
		break;
	default:
		break;
	}
}

bool Enemy::checkPlayerCollision(int _playerSize)
{
	
	if (toPlayerDir < _playerSize / 2 && toPlayerDir > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Enemy::isCanRemove() const
{
	return !isAlive;
}
void Enemy::move(Vector2 _playerPos)
{
	float dirX = _playerPos.x - pos.x;
	float dirY = _playerPos.y - pos.y;
	toPlayerDir = sqrtf(dirX * dirX + dirY * dirY);
	if (toPlayerDir != 0)
	{
		float normalizedX = dirX / toPlayerDir;
		float normalizedY = dirY / toPlayerDir;
		pos.x += static_cast<int>(volocity * normalizedX);
		pos.y += static_cast<int>(volocity * normalizedY);
	}
	radian = atan2(dirY, dirX);
	for (int i = 0;i < 4;i++)
	{
		rotatedVector[i].x = vector[i].x * cosf(radian) - vector[i].y * sinf(radian);
		rotatedVector[i].y = vector[i].y * cosf(radian) + vector[i].x * sinf(radian);
	}

}

void Enemy::update(Vector2 _playerPos)
{
	
	if (isValid)
	{
		this->move(_playerPos);
		this->bulletCollide();
	}
	else
	{
		if (!Novice::IsPlayingAudio(playHandle) || playHandle == -1)
		{
			playHandle = Novice::PlayAudio(deadSound, 0, 0.1f);
		}
		disappearTimer++;
		if (disappearTimer >= disappearTime)
		{
			//totalScore += score;
			isAlive = false;
		}
	}

}

void Enemy::draw()
{
	Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y), 20, 20, 0.0f, 0xFF69B4FF, kFillModeSolid);
}

void Enemy::bulletCollide()
{
	for (Bullet* bullet : bulletList)
	{
		if (bullet->checkEnemyCollision(pos,size))
		{
			hp -= bullet->getDamage();
			if (hp <= 0)
			{

				isValid = false;

			}
			bullet->setCanRemove(true);
		}
	}
}


int Enemy::getDamage()
{
	return damage;
}

int Enemy::getHealth()
{
	return hp;
}

float Enemy::getPos()
{
	return pos.x;
}

int Enemy::getScore()
{
	return score;
}

bool Enemy::getIsAlive()
{
	return isAlive;
}

void Enemy::setAlive(bool _isAlive)
{
	isAlive = _isAlive;
}

void Enemy::setIsValid(bool _isValid)
{
	isValid = _isValid;
}
