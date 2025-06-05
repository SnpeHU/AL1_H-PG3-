#pragma once
#include "IScene.h"
class TitleScene : public IScene {
public:
	TitleScene() = default;
	~TitleScene() override = default;
	// シーンの初期化
	void Init() override;
	// シーンの更新
	void Update() override;
	// シーンの描画
	void Draw() override;
private:
};