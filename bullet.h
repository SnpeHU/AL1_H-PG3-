#pragma once
#include <Novice.h>
#include <Vector2.h>
#include <functional>

class Bullet
{
public:
	Bullet() = default;;
	~Bullet() = default;

	void update();
	void draw();

	void setDamage(int _damage);
	int getDamage();

	void setPos(float _x, float _y);
	const Vector2& getPos();//const

	void setToward(Vector2 _toward);
	
	//const Vector2& getSize();//const

	void setVelocity(float _velocity);
	

	void setValid(bool _isValid);
	bool getValid();

	

	//void setCallback(std::function<void> _callback);
	void setCanRemove(bool _iscanRemove);
	bool isCanRemove() const;

	bool checkPos();//弾が画面の外に出ているかどうか

	bool checkEnemyCollision(Vector2 _enemyPos,int size);
protected:


	int capacity = 1;//占用
	float velocity = 12;
	Vector2 pos;
	Vector2 toward;
	int size = 15;
	//Vector2 velocity;
	int damage = 1;
	//int coolTime = 30;
	//int timer = 0;

	bool isValid = true;//子弹是否有效
	bool canRemove = false;

	int bulletPic = Novice::LoadTexture("./Resoures/images/player/bullet.png");

	//std::function<void> callback;//子弹碰撞回调函数
	//enemyID 识别碰撞对象
};
