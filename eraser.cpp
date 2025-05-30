#include "eraser.h"

eraser::eraser()
{
		hp = 100;
		volocity = 8;
		size = 32;
		damage = 1;
		picSize = 64.0f;
		score = 100;
}

void eraser::move(Vector2 _playerPos)
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

}

void eraser::draw()
{
}
