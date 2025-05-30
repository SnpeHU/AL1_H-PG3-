#include "enemy_zombie.h"
#include <stdlib.h>

Zombie::Zombie()
{
	hp = 2;
	volocity = 3;
	size = 26;
	damage = 1;
	picSize = 64.0f;
	score = 100;
}

void Zombie::draw()
{
	Novice::DrawQuad(int(pos.x + rotatedVector[0].x), int(pos.y + rotatedVector[0].y),
		int(pos.x + rotatedVector[1].x), int(pos.y + rotatedVector[1].y),
		int(pos.x + rotatedVector[2].x), int(pos.y + rotatedVector[2].y),
		int(pos.x + rotatedVector[3].x), int(pos.y + rotatedVector[3].y),
		0, 0, static_cast<int>(picSize), static_cast<int>(picSize), isValid?alivePic: deadPic, WHITE);
	//Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y), size,size,0.0f,BLACK,kFillModeWireFrame);
}
