#pragma once
#include "enemy.h"
class eraser : public Enemy
{
public:
	eraser();
	~eraser() = default;

	void move(Vector2 _playerPos);
	void draw();

private:
	Vector2 toward;
	
};

