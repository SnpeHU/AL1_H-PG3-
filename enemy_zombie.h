#pragma once
#include <enemy.h>
#include <Novice.h>
class Zombie : public Enemy
{
public:
	Zombie();
	~Zombie() = default;

	int alivePic = Novice::LoadTexture("./Resoures/images/enemy/bug01.png");
	int deadPic = Novice::LoadTexture("./Resoures/images/enemy/bug02.png");

	void draw();

};

