#include "scenemanager.h"
#include "TitleScene.h"

extern std::list<Enemy*> enemyList;

SceneManager::SceneManager()
{
	currentScene = TITLE;
	currentState = READY;

	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	//sceneArr_[GAME] = std::make_unique<GameScene>();
	//sceneArr_[END] = std::make_unique<EndScene>();
}

void SceneManager::setScene(Scene _scene)
{
	if (!Novice::IsPlayingAudio(playHandle) || playHandle == -1)
	{
		playHandle = Novice::PlayAudio(changeScene, 0, 0.5f);
	}
	currentScene = _scene;
}

void SceneManager::setState(GameState _state)
{
	currentState = _state;
}

void SceneManager::enemysRespawn()
{
	respawnTimer++;
	if (respawnTimer >= respawnTime)
	{
		Enemy* enemy = new Zombie();
		enemyList.push_back(enemy);
		respawnTimer = 0;
		//Novice::ConsolePrintf("%d",enemy->getHealth());
		
	}
	if (level > 3)
	{
		if (respawnTimer >= respawnTime)
		{
			Enemy* enemy = new eraser();
			enemyList.push_back(enemy);
			respawnTimer = 0;
			//Novice::ConsolePrintf("%d",enemy->getHealth());

		}
	}

}

void SceneManager::updateEnemys(Player& player)
{
	//for (Enemy* enemy : enemyList)
//{
//	if (enemy->isCanRemove())
//	{

//	}
//}
	for (Enemy* enemy : enemyList)
	{
		if (!enemy->getIsAlive())
		{
			totalScore += enemy->getScore();
		}


	}
	enemyList.erase(std::remove_if(
		enemyList.begin(), enemyList.end(),
		[](const Enemy* enemy)
		{
			bool deletable = enemy->isCanRemove();
			if (deletable) delete enemy;
			return deletable;
		}),
		enemyList.end());

	
	for (Enemy* enemy : enemyList)
	{
		enemy->update(player.getPos());
		
		
	}

}

void SceneManager::levelUp()
{
	levelUpTimer++;
	if (levelUpTimer % levelUpTime == 0)
	{
		level += 1;
		respawnTime -= 5;
	}
}

void SceneManager::reset()
{
	level = 0;
	totalScore = 0;
	respawnTimer = 0;
	levelUpTimer = 0;
	targetNumber = 0;
	levelUpTime = 480;
	respawnTime = 100;
	//isStart = false;
	//isEnd = false;
}

void SceneManager::checkPlayer(const Player& player)
{
	if (!player.getIsAlive())
	{
		//isEnd = true;
		setState(END);
	}
}

void SceneManager::drawEnemys()
{
	for (Enemy* enemy : enemyList)
	{
		enemy->draw();
	}
}

void SceneManager::UIprocess()
{
	targetLevel = level;
	targetNumber = totalScore;
	for (int i = 0; i < length; i++)
	{
		numberArray[i] = int(targetNumber / pow(10.0, length - (i + 1)));
		targetNumber %= int(pow(10.0, length - (i + 1)));
	}
	for (int i = 0; i < levelLength; i++)
	{
		levelArray[i] = int(targetLevel / pow(10.0, levelLength - (i + 1)));
		targetLevel %= int(pow(10.0, levelLength - (i + 1)));
	}
}

void SceneManager::drawUI()
{
	switch (currentScene)
	{
	case SceneManager::TITLE:
		Novice::DrawSprite(0, 0, backGroundUI, 1.0f, 1.0f, 0.0f, WHITE);
		Novice::DrawSprite(0, 0, titleUI, 1.0f, 1.0f, 0.0f, WHITE);
		Novice::DrawSprite(500, 500, startUI, 1.0f, 1.0f, 0.0f, WHITE);

		
		break;
	case SceneManager::GAME:
		Novice::DrawSprite(0, 0, backGroundUI, 1.0f, 1.0f, 0.0f, WHITE);
		Novice::DrawSprite(0, 600, guideUI, 1.0f, 1.0f, 0.0f, WHITE);
		Novice::DrawSprite(980, 80, levelUI, 1.0f, 1.0f, 0.0f, WHITE);
		for (int i = 0;i < length;i++)
		{
			Novice::DrawSprite(static_cast<int>(scorePos.x) + i * numberPosInterval, static_cast<int>(scorePos.y), numberImage[numberArray[i]], 0.4f, 0.4f, 0.0f, WHITE);
		}
		for (int i = 0;i <levelLength;i++)
		{
			Novice::DrawSprite(static_cast<int>(levelPos.x) + i * numberPosInterval, static_cast<int>(levelPos.y), numberImage[levelArray[i]], 0.4f, 0.4f, 0.0f, WHITE);
		}
		if (currentState == READY)
		{
			Novice::DrawSprite(400, 500, startUI, 0.8f, 0.8f, 0.0f, WHITE);
		}
		if (currentState == END)
		{
			Novice::DrawSprite(0, 0, gameOverUI, 1.0f, 1.0f, 0.0f, WHITE);
			Novice::DrawSprite(600, 500, endText, 1.0f, 1.0f, 0.0f, WHITE);
		}
		break;
	default:
		break;
	}
	
}

int SceneManager::Run()
{
	while (Novice::ProcessMessage() == 0)
	{

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




