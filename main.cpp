#include <Novice.h>
#include <player.h>
#include <weapen.h>
#include <Vector2.h>
#include <scenemanager.h>
#include <enemy.h>
//#include "InputManager.h"

const char kWindowTitle[] = "GC1A_05_コウ_ホウケイ_Notebook Cleaner";
const int windowRight = 1280;
const int windowbottom = 720;
//int totalScore = 0;

std::list<Bullet*> bulletList;
std::list<Enemy*> enemyList;

  
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	SceneManager sceneManager;

	sceneManager.Run();

	// ライブラリの終了
	Novice::Finalize();

	return 0;
}
