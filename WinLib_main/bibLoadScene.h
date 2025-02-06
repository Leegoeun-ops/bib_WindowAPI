#pragma once
#include "..\\Win_SOURCE\\bibSceneManager.h"
#include "bibPlayScene.h"
#include "bibTitleScene.h"
namespace bib
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}