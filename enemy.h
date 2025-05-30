#pragma once
#include <Vector2.h>
#include <stdlib.h>
#include <corecrt_math.h>
#include <Novice.h>
#include <bullet.h>
extern const int windowRight;
extern const int windowbottom;

//extern int totalScore;

extern std::list<Bullet*> bulletList;

class Enemy
{
public: 
	enum class SpawnDir
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

public:
	Enemy();
	~Enemy() = default;
	
	bool checkPlayerCollision(int _playerSize);
	bool isCanRemove() const;

	void move(Vector2 _playerPos);
	void update(Vector2 _playerPos);//move

	virtual void draw();

	int getDamage();
	int getHealth();
	float getPos();
	int getScore();
	bool getIsAlive();

	void setAlive(bool _Alive);
	void setIsValid(bool _isValid);

	void bulletCollide();
protected:
	int hp = 1;
	int volocity = 2;
	int size = 32;
	float picSize = 64.0f;
	int damage = 1;
	float toPlayerDir = -1.0f;

	int disappearTime = 90;
	int disappearTimer = 0;

	int score = 100;
	bool isChaes = false;

	int deadSound = Novice::LoadAudio("./Resoures/sounds/die.wav");
	int playHandle = -1;

	Vector2 pos;
	Vector2 vector[4]//Enemyの頂点
	{
		vector[0].x = -picSize / 2 ,vector[0].y = -picSize / 2 ,
		vector[1].x = picSize / 2 ,vector[1].y = -picSize / 2 ,
		vector[2].x = -picSize / 2 ,vector[2].y = picSize / 2 ,
		vector[3].x = picSize / 2 ,vector[3].y = picSize / 2
	};
	Vector2 rotatedVector[4]//Playerの回転後頂点
	{
		rotatedVector[0].x = -picSize / 2 ,rotatedVector[0].y = -picSize / 2 ,
		rotatedVector[1].x = picSize / 2 ,rotatedVector[1].y = -picSize / 2 ,
		rotatedVector[2].x = -picSize / 2 ,rotatedVector[2].y = picSize / 2 ,
		rotatedVector[3].x = picSize / 2 ,rotatedVector[3].y = picSize / 2
	};
	float radian = 0.0f;
	
	bool isValid = true;
	bool isAlive = true;




};