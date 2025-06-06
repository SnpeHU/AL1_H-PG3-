#include "EndScene.h"
#include "InputManager.h"

void EndScene::Init()
{
}

void EndScene::Update()
{
	InputManager* inputManager = InputManager::GetInstance();
	if (inputManager->IsKeyPressed(DIK_BACK) && !inputManager->IsPreKeyPressed(DIK_BACK))
	{
		sceneNo = SCENE::TITLE;
	}
	if (inputManager->IsKeyPressed(DIK_SPACE) && !inputManager->IsPreKeyPressed(DIK_SPACE))
	{
		sceneNo = SCENE::GAME;
	}
}

void EndScene::Draw()
{
	Novice::DrawSprite(0, 0, backGroundUI, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 0, gameOverUI, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(600, 500, endText, 1.0f, 1.0f, 0.0f, WHITE);

}
