#pragma once
#include <Novice.h>

class InputManager {
public:
	static InputManager* GetInstance();


	InputManager() = default;
	~InputManager() = default;

	// キー入力を受け取る
	void GetHitKeyStateAll() {
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
	}
	// キー入力状態を取得
	bool IsKeyPressed(int key) const {
		return keys[key] != 0;
	}
	// 前回のキー入力状態を取得
	bool IsPreKeyPressed(int key) const {
		return preKeys[key] != 0;
	}


private:
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	static InputManager* instance; // シングルトンインスタンス
};