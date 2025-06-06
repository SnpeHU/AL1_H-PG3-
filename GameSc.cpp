#include "GameSc.h"
#include "InputManager.h"
extern std::list<Enemy*> enemyList;
extern std::list<Bullet*> bulletList;
void GameSc::Init()
{
	player = std::make_unique<Player>();
	weapon = std::make_unique<Weapen>();
	currentState = READY;
}

void GameSc::Update()
{
	InputManager* inputManager = InputManager::GetInstance();
	if (inputManager->IsKeyPressed(DIK_BACK) && !inputManager->IsPreKeyPressed(DIK_BACK))
	{
		sceneNo = SCENE::TITLE;
	}
	Novice::GetMousePosition(&mousePos.x, &mousePos.y);
	if (Novice::IsPressMouse(0)) {

		weapon->Fire(player->getPos(), player->playerToward);
	}

	UIprocess();
	switch (currentState)
	{
	case GameState::READY:

		if (inputManager->IsKeyPressed(DIK_SPACE) && !inputManager->IsPreKeyPressed(DIK_SPACE))
		{
			currentState = START;
	
		}

		break;
	case GameState::START:
		//levelUp();
		levelUp();
		enemysRespawn();
		updateEnemys();
		if (!player->getIsAlive())
		{
			bulletList.clear();
			enemyList.clear();
			reset();
			player->reset();
			sceneNo = SCENE::END;
		}
	default:
		break;
	}


	player->move();
	player->rotate(mousePos.x, mousePos.y);
	player->collide();
	weapon->updateBullets();
	weapon->update();
}

void GameSc::Draw()
{
	

	Novice::DrawSprite(0, 0, backGroundUI, 1.0f, 1.0f, 0.0f, WHITE);
	player->draw();
	weapon->drawBullets();
	drawEnemys();
	Novice::DrawSprite(0, 600, guideUI, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(980, 80, levelUI, 1.0f, 1.0f, 0.0f, WHITE);
	for (int i = 0;i < length;i++)
	{
		Novice::DrawSprite(static_cast<int>(scorePos.x) + i * numberPosInterval, static_cast<int>(scorePos.y), numberImage[numberArray[i]], 0.4f, 0.4f, 0.0f, WHITE);
	}
	for (int i = 0;i < levelLength;i++)
	{
		Novice::DrawSprite(static_cast<int>(levelPos.x) + i * numberPosInterval, static_cast<int>(levelPos.y), numberImage[levelArray[i]], 0.4f, 0.4f, 0.0f, WHITE);
	}
	if (currentState == READY)
	{
		Novice::DrawSprite(400, 500, startUI, 0.8f, 0.8f, 0.0f, WHITE);
	}
}

void GameSc::enemysRespawn()
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

void GameSc::updateEnemys()
{
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
		enemy->update(player->getPos());


	}
}

void GameSc::drawEnemys()
{
	for (Enemy* enemy : enemyList)
	{
		enemy->draw();
	}
}

void GameSc::levelUp()
{
	levelUpTimer++;
	if (levelUpTimer % levelUpTime == 0)
	{
		level += 1;
		respawnTime -= 5;
	}
}

void GameSc::UIprocess()
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

void GameSc::reset()
{
	level = 0;
	totalScore = 0;
	respawnTimer = 0;
	levelUpTimer = 0;
	targetNumber = 0;
	levelUpTime = 480;
	respawnTime = 100;
}
