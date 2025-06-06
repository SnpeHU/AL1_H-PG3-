#pragma once
#include<Vector2.h>
#include <list>
#include <eraser.h>
#include <Novice.h>
#include "memory"
//#include "IScene.h"
#include "InputManager.h"
#include "TitleScene.h"

class SceneManager
{
public:
	
	
private:
	//Scene管理
	std::unique_ptr<IScene> sceneArr_[3];
	int currentSceneNo;
	int prevSceneNo;


	//Sounds
	int changeScene = Novice::LoadAudio("./Resoures/sounds/changeScene.wav");
	int playHandle = -1;


public:
	SceneManager();
	~SceneManager() = default;

	int Run();
};

