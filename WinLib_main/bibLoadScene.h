#pragma once
#include "..\\Win_SOURCE\\bibSceneManager.h"
#include "bibPlayScene.h"
namespace bib
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}