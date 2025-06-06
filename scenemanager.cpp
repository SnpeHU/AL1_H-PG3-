#include "scenemanager.h"
#include "TitleScene.h"
#include "GameSc.h"
#include "EndScene.h"
#include "InputManager.h"
#include "memory"
extern std::list<Enemy*> enemyList;

SceneManager::SceneManager()
{

	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[GAME] = std::make_unique<GameSc>();
	sceneArr_[END] = std::make_unique<EndScene>();
	currentSceneNo = TITLE;
	
	//sceneArr_[GAME] = std::make_unique<GameScene>();

}
int SceneManager::Run()
{
	while (Novice::ProcessMessage() == 0)
	{
		InputManager* inputManager = InputManager::GetInstance();

		Novice::BeginFrame();
		inputManager->GetHitKeyStateAll();
		prevSceneNo = currentSceneNo;
		currentSceneNo = sceneArr_[currentSceneNo]->GetSceneNo();

		if (currentSceneNo != prevSceneNo)
		{
			sceneArr_[currentSceneNo]->Init();
		}

		sceneArr_[currentSceneNo]->Update();
		sceneArr_[currentSceneNo]->Draw();

		Novice::EndFrame();
		if (inputManager->IsKeyPressed(DIK_ESCAPE) && inputManager->IsPreKeyPressed(DIK_ESCAPE))
		{
			break;
		}

		
	}
	return 0;

}




