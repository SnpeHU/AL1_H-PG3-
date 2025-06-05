#include <Novice.h>
#include <player.h>
#include <weapen.h>
#include <Vector2.h>
#include <scenemanager.h>
#include <enemy.h>


const char kWindowTitle[] = "GC1A_05_コウ_ホウケイ_Notebook Cleaner";
struct IntVector2
{
	int x;
	int y;
};
const int windowRight = 1280;
const int windowbottom = 720;
//int totalScore = 0;

std::list<Bullet*> bulletList;
std::list<Enemy*> enemyList;
  
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	//char keys[256] = {0};
	//char preKeys[256] = {0};

	SceneManager sceneManager;


	IntVector2 mousePos = {0,0};
	Player player;
	Weapen weapen;


	// ウィンドウの×ボタンが押されるまでループ
	//while (Novice::ProcessMessage() == 0) {
	//	// フレームの開始
	//	Novice::BeginFrame();

	//	// キー入力を受け取る
	//	memcpy(preKeys, keys, 256);
	//	Novice::GetHitKeyStateAll(keys);

	//	///
	//	/// ↓更新処理ここから
	//	///
	//	switch (sceneManager.currentScene)
	//	{
	//	case SceneManager::Scene::TITLE:
	//		if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] != 0)
	//		{
	//			sceneManager.setScene(SceneManager::Scene::GAME);
	//		}
	//		break;
	//	case SceneManager::GAME:
	//		sceneManager.UIprocess();
	//		switch (sceneManager.currentState)
	//		{
	//		case SceneManager::GameState::READY:
	//			
	//			if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] != 0)
	//			{
	//				sceneManager.setState(SceneManager::GameState::START);
	//			}
	//			break;
	//		case SceneManager::GameState::START:
	//			sceneManager.levelUp();
	//			
	//			sceneManager.enemysRespawn();
	//			sceneManager.updateEnemys(player);
	//			sceneManager.checkPlayer(player);
	//			break;
	//		case SceneManager::GameState::END:
	//		
	//			bulletList.clear();
	//			enemyList.clear();
	//			
	//			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
	//			{
	//				player.reset();
	//				sceneManager.reset();
	//				sceneManager.setState(SceneManager::GameState::READY);
	//			}
	//			break;
	//		default:
	//			break;
	//		}


	//		if (preKeys[DIK_BACKSPACE] == 0 && keys[DIK_BACKSPACE] != 0)
	//		{
	//			bulletList.clear();
	//			enemyList.clear();
	//			sceneManager.setScene(SceneManager::Scene::TITLE);
	//			player.reset();
	//			sceneManager.reset();
	//			sceneManager.setState(SceneManager::GameState::READY);
	//		}
	//		Novice::GetMousePosition(&mousePos.x, &mousePos.y);
	//		player.move(keys);
	//		player.rotate(mousePos.x, mousePos.y);
	//		player.collide();
	//		if (Novice::IsPressMouse(0))
	//		{

	//			weapen.Fire(player.getPos(), player.playerToward);
	//		}
	//		weapen.updateBullets();
	//		weapen.update();

	//		break;
	//	default:
	//		break;
	//	}
	//	
	//	///
	//	/// ↑更新処理ここまで
	//	///

	//	///
	//	/// ↓描画処理ここから
	//	///  
	//	switch (sceneManager.currentScene)
	//	{
	//	case SceneManager::TITLE:
	//		sceneManager.drawUI();
	//		break;
	//	case SceneManager::GAME:
	//		sceneManager.drawUI();

	//		//Novice::ScreenPrintf(20, 20, "%d", sceneManager.isStart);
	//		switch (sceneManager.currentState)
	//		{
	//		case SceneManager::GameState::READY:
	//			
	//			weapen.drawBullets();
	//			player.draw();
	//			break;
	//		case SceneManager::GameState::START:
	//			
	//			weapen.drawBullets();
	//			sceneManager.drawEnemys();
	//			//sceneManager.UIprocess();
	//			player.draw();
	//			
	//			break;
	//		case SceneManager::GameState::END:
	//			break;
	//		default:
	//			break;
	//		}

	//		break;
	//	default:
	//		break;
	//	}
	//	
	//	/// ↑描画処理ここまで
	//	///

	//	// フレームの終了
	//	Novice::EndFrame();

	//	// ESCキーが押されたらループを抜ける
	//	if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
	//		break;
	//	}
	//}
	sceneManager.Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
