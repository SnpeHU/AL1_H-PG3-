#pragma once
#include "IScene.h"
#include <Novice.h>
class EndScene : public IScene {
public:
	EndScene() = default;
	~EndScene() override = default;
	// シーンの初期化
	void Init() override;
	// シーンの更新
	void Update() override;
	// シーンの描画
	void Draw() override;
private:
	int backGroundUI = Novice::LoadTexture("./Resoures/images/UI/background.png");
	int gameOverUI = Novice::LoadTexture("./Resoures/images/UI/gameover.png");
	int endText = Novice::LoadTexture("./Resoures/images/UI/endText.png");
};