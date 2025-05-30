#pragma once
#include<Vector2.h>
#include <list>
#include<enemy.h>
#include<enemy_zombie.h>
#include <eraser.h>
#include <Novice.h>
#include <player.h>

#include "memory"
#include "IScene.h"
#include "InputManager.h"



class SceneManager
{
public:
	enum Scene
	{
		TITLE,
		GAME
	};
	Scene currentScene;

	enum GameState
	{
		READY,
		START,
		END
	};
	GameState currentState;
	
	
private:
	//Scene管理
	std::unique_ptr<IScene> sceneArr_[3];
	int currentSceneNo;
	int prevSceneNo;

	//Input
	//InputManager inputManager;
	std::unique_ptr<InputManager> inputManager = std::make_unique<InputManager>();

	
	//UI画像
	int startUI = Novice::LoadTexture("./Resoures/images/UI/startText.png");
	int endText = Novice::LoadTexture("./Resoures/images/UI/endText.png");
	int titleUI = Novice::LoadTexture("./Resoures/images/UI/title.png");
	int levelUI = Novice::LoadTexture("./Resoures/images/UI/level.png");
	int backGroundUI = Novice::LoadTexture("./Resoures/images/UI/background.png");
	int gameOverUI = Novice::LoadTexture("./Resoures/images/UI/gameover.png");
	int guideUI = Novice::LoadTexture("./Resoures/images/UI/guide.png");

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
		Novice::LoadTexture("./Resoures/images/UI/9.png"),
	};
	int numberArray[5] = {};
	int levelArray[2] = {};
	int levelLength = sizeof(levelArray) / sizeof(levelArray[0]);
	int length = sizeof(numberArray) / sizeof(numberArray[0]);
	int numberPosInterval = 40;
	int targetNumber = 0;
	int targetLevel = 0;
	Vector2 scorePos = {1030.0f,30.0f };
	Vector2 levelPos = {1150.0f,100.0f};

	//Sounds
	int changeScene = Novice::LoadAudio("./Resoures/sounds/changeScene.wav");
	int playHandle = -1;

	//点数
	int totalScore = 0;
 
	//Level管理
	int level = 0;
	int levelUpTime = 480;
	int levelUpTimer = 0;
	
	//Enemy管理
	int respawnTime = 100;
	int respawnTimer = 0;
	//int respawnCount = 0;


public:
	SceneManager();
	~SceneManager() = default;

	void setScene(Scene _scene);
	void setState(GameState _state);

	void enemysRespawn();
	void updateEnemys(Player& player);

	void levelUp();
	void reset();
	
	void checkPlayer(const Player& player);//プレーヤー死亡、アップグレード

	void drawEnemys();
	void UIprocess();
	void drawUI();

	int Run();
};

