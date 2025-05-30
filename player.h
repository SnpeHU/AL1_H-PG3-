#pragma once
#include <Novice.h>
#include <Vector2.h>
#include <dinput.h>
#include <corecrt_math.h>
#include <enemy.h>
#include <list>



class Player
{
public:
	Player() = default;
	~Player() = default;


	void move(char* keys);
	void collide();

	void rotate(int _mouseX, int _mouseY);
	void setRotate(float goalDegree);
	void draw();

	Vector2 getPos(); 

	bool getIsAlive() const;

	void reset();


protected:
	
	bool isUp = false;
	bool isDown = false;
	bool isLeft = false;
	bool isRight = false;

	const int maxSpeed = 5;
	float acceleration = 0.1f;
	float rotateSpeed = 2.0;

	double normolizedX = 0;
	double normolizedY = 0;

	int maxHp = 1;
	
	bool isAlive = true;
	
	//int level = 1;
	//int Xp = 10;
	//int currentXp = 0;

public:

	Vector2 playerToward = { 1.0f,0.0f };
	int currentHp = 1;
	
	int playerBottom = Novice::LoadTexture("./Resoures/images/player/tank.png");
	int playerTop = Novice::LoadTexture("./Resoures/images/player/tank03.png");
	float currentDegree = 0.0f;
	float currentSpeed = 0;
	float size = 64.0f;
	
	Vector2 pos = { 400.0f, 400.0f };


	Vector2 vector[4]//Playerの頂点
	{
		vector[0].x = -size / 2 ,vector[0].y = -size / 2 ,
		vector[1].x = size / 2 ,vector[1].y = -size / 2 ,
		vector[2].x = -size / 2 ,vector[2].y = size / 2 ,
		vector[3].x = size / 2 ,vector[3].y = size / 2
	};
	Vector2 rotatedVector[4]//Playerの回転後頂点
	{
		rotatedVector[0].x = -size / 2 ,rotatedVector[0].y = -size / 2 ,
		rotatedVector[1].x = size / 2 ,rotatedVector[1].y = -size / 2 ,
		rotatedVector[2].x = -size / 2 ,rotatedVector[2].y = size / 2 ,
		rotatedVector[3].x = size / 2 ,rotatedVector[3].y = size / 2
	};
};

