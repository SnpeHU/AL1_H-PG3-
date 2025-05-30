#include "player.h"
#include <Novice.h>
#define PI 3.14159265
extern std::list<Enemy*> enemyList;

extern const int windowRight;
extern const int windowbottom;
void Player::move(char* keys)
{
	static int preDirX = 0;
	static int preDirY = 0;
	isUp = false;
	isDown = false;
	isLeft = false;
	isRight = false;

		if (keys[DIK_W])
		{
			isUp = true;

		}
		if (keys[DIK_S])
		{
			isDown = true;

		}
		if (keys[DIK_A])
		{
			isLeft = true;

		}
		if (keys[DIK_D])
		{
			isRight = true;

		}

	int playerDirX = isRight - isLeft;
	int playerDirY = isDown - isUp;
	double dirLength = sqrt(playerDirX * playerDirX + playerDirY * playerDirY);
	if (dirLength != 0)
	{
		if (currentSpeed < maxSpeed)
		{
			currentSpeed += acceleration;
		}
		normolizedX = playerDirX / dirLength;
		normolizedY = playerDirY / dirLength;
		pos.x += int(currentSpeed * normolizedX);
		pos.y += int(currentSpeed * normolizedY);
	}
	else
	{
		if (currentSpeed > 0)
		{
			currentSpeed -= acceleration;
		}
		pos.x += int(currentSpeed * normolizedX);
		pos.y += int(currentSpeed * normolizedY);
	}

	if (currentHp < 0)
	{
		isAlive = false;
	}

}

void Player::rotate(int _mouseX, int _mouseY)
{

	float dirX = _mouseX - pos.x;
	float dirY = _mouseY - pos.y;

	double rotation = atan2(dirY, dirX);
	float goalDegree = float(rotation * 180 / PI);
	setRotate(goalDegree);
}
void Player::reset()
{
	isAlive = true;
	currentHp = maxHp;
	playerToward = { 1.0f,0.0f };
	pos = { 400.0f, 400.0f };
}
void Player::setRotate(float goalDegree)
{ 
	//if (goalDegree > currentDegree)
	//{

	//	currentDegree += rotateSpeed;
	//}
	//if (goalDegree < currentDegree)
	//{
	//	currentDegree -= rotateSpeed;
	//	//转动角度

	//}
	float radian = float(goalDegree * PI / 180);
		for (int i = 0;i < 4;i++)
		{
			rotatedVector[i].x = vector[i].x * cosf(radian) - vector[i].y * sinf(radian);
			rotatedVector[i].y = vector[i].y * cosf(radian) + vector[i].x * sinf(radian);
		}
		
		playerToward.x = cosf(radian);
		playerToward.y = sinf(radian);
}


void Player::draw()
{
	Novice::DrawQuad(int(pos.x + vector[0].x), int(pos.y + vector[0].y),
		int(pos.x + vector[1].x), int(pos.y + vector[1].y),
		int(pos.x + vector[2].x), int(pos.y + vector[2].y),
		int(pos.x + vector[3].x), int(pos.y + vector[3].y),
		0, 0, (int)size, (int)size, playerBottom, WHITE);
	//Novice::DrawSprite(static_cast<int>(pos.x - size/2), static_cast<int>(pos.y - size / 2),playerTop,0.1f,0.1f,1.0f,WHITE);
	Novice::DrawQuad(int(pos.x + rotatedVector[0].x), int(pos.y + rotatedVector[0].y),
		int(pos.x + rotatedVector[1].x), int(pos.y + rotatedVector[1].y),
		int(pos.x + rotatedVector[2].x), int(pos.y + rotatedVector[2].y),
		int(pos.x + rotatedVector[3].x), int(pos.y + rotatedVector[3].y),
		0, 0, (int)size, (int)size, playerTop, WHITE);

	Novice::DrawLine(int(pos.x), int(pos.y), int(pos.x + playerToward.x * 100), int(pos.y + playerToward.y * 100),WHITE);
}

void Player::collide()
{
	for (Enemy* enemy : enemyList)
	{
		if (enemy->checkPlayerCollision((int)size))
		{
			currentHp -= enemy->getDamage();
			enemy->setIsValid(false);
		}
	}
	if (currentHp <= 0)
	{
		isAlive = false;
	}

}

Vector2 Player::getPos()
{
	return pos;
}
bool Player::getIsAlive() const
{
	return isAlive;
}

