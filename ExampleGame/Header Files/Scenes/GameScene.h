#pragma once
#include "Scene.h"
#include <memory>
#include "Managers.h"
#include "KodeboldsMath.h"

class GameScene : public Scene
{
private:
	//Managers
	std::shared_ptr<ECSManager> mEcsManager = ECSManager::Instance();
	std::shared_ptr<NetworkManager> mNetworkManager = NetworkManager::Instance();
#ifdef  DIRECTX
	std::shared_ptr<InputManager_DX> mInputManager = InputManager_DX::Instance();
#elif OPENGL
	std::shared_ptr<InputManager_GL> mInputManager = InputManager_GL::Instance();
#endif
	std::shared_ptr<SceneManager> mSceneManager = SceneManager::Instance();

public:
	//Structors
	GameScene();
	~GameScene();

	void Update() override;
	void OnLoad() override;
	void OnUnload() override;
};