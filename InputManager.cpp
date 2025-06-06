#include "InputManager.h"
InputManager* InputManager::instance = nullptr;

InputManager* InputManager::GetInstance()
{
	if (!instance) {
		instance = new InputManager();
	}
	return instance;
}
