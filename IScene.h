#pragma once
enum class SCENE {
	TITLE,
	GAME,
	END
};
class IScene {
protected:
	static int sceneNo;

public:
	virtual ~IScene() = default;
	// シーンの初期化
	virtual void Init() = 0;
	// シーンの更新
	virtual void Update() = 0;
	// シーンの描画
	virtual void Draw() = 0;

	// 次のシーン番号を取得
	static int GetSceneNo();

};
