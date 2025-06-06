#include "TitleScene.h"
#include "InputManager.h"
#include "memory"


void TitleScene::Init()
{
}

void TitleScene::Update()
{
	InputManager* inputManager = InputManager::GetInstance();
	if (inputManager->IsKeyPressed(DIK_SPACE) && !inputManager->IsPreKeyPressed(DIK_SPACE))
	{
		sceneNo = SCENE::GAME;
	}
}

void TitleScene::Draw()
{
	Novice::DrawSprite(0, 0, backGroundUI, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 0, titleUI, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(500, 500, startUI, 1.0f, 1.0f, 0.0f, WHITE);
}
