#pragma once
#include <bullet.h>
#include<player.h>
#include<Vector2.h>
extern std::list<Bullet*> bulletList;
class Weapen
{
public:
	Weapen();
	~Weapen() = default;
	void Fire(Vector2 _pos,Vector2 _toward);
	void updateBullets();
	void switchBullet();
	void drawBullets();
	void update();
private:
	const static int maxMagazine = 6;//マガジン容量
	int currentMagazine = 0;

	int fireCoolTime = 30;
	int attackTimer = 0;
	bool canFire = true;
	
	//Bullet bullet;
	
public:
	//Bullet bullet[maxMagazine];
	

};
