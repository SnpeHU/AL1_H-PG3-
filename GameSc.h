#pragma once
#include "IScene.h"
#include <Novice.h>
#include <Vector2.h>
#include "player.h"
#include "weapen.h"
#include "memory"
#include "enemy_zombie.h"
#include "eraser.h"
struct IntVector2
{
	int x;
	int y;
};
class GameSc : public IScene {
public:
	GameSc() = default;
	~GameSc() override = default;
	// シーンの初期化
	void Init() override;
	// シーンの更新
	void Update() override;
	// シーンの描画
	void Draw() override;

	void enemysRespawn();
	void updateEnemys();
	void drawEnemys();
	void levelUp();
	void UIprocess();

	void reset();
public:
	enum GameState
	{
		READY,
		START,
		END
	};
	GameState currentState;
private:
	//object管理
	std::unique_ptr<Player> player = nullptr;
	std::unique_ptr<Weapen> weapon = nullptr;



	//UI画像
	int backGroundUI = Novice::LoadTexture("./Resoures/images/UI/background.png");
	int levelUI = Novice::LoadTexture("./Resoures/images/UI/level.png");
	int guideUI = Novice::LoadTexture("./Resoures/images/UI/guide.png");
	int startUI = Novice::LoadTexture("./Resoures/images/UI/startText.png");
	int numberImage[10] = {
		Novice::LoadTexture("./Resoures/images/UI/0.png"),
		Novice::LoadTexture("./Resoures/images/UI/1.png"),
		Novice::LoadTexture("./Resoures/images/UI/2.png"),
		Novice::LoadTexture("./Resoures/images/UI/3.png"),
		Novice::LoadTexture("./Resoures/images/UI/4.png"),
		Novice::LoadTexture("./Resoures/images/UI/5.png"),
		Novice::LoadTexture("./Resoures/images/UI/6.png"),
		Novice::LoadTexture("./Resoures/images/UI/7.png"),
		Novice::LoadTexture("./Resoures/images/UI/8.png"),
		Novice::LoadTexture("./Resoures/images/UI/9.png")
	};

	int numberArray[5] = {};
	int levelArray[2] = {};
	int levelLength = sizeof(levelArray) / sizeof(levelArray[0]);
	int length = sizeof(numberArray) / sizeof(numberArray[0]);
	int numberPosInterval = 40;
	int targetNumber = 0;
	int targetLevel = 0;
	Vector2 scorePos = { 1030.0f,30.0f };
	Vector2 levelPos = { 1150.0f,100.0f };

	//点数
	int totalScore = 0;

	//Level管理
	int level = 0;
	int levelUpTime = 480;
	int levelUpTimer = 0;

	//Enemy管理
	int respawnTime = 100;
	int respawnTimer = 0;

	IntVector2 mousePos = { 0,0 };
};
