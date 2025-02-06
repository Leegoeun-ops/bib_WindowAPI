#include "bibPlayScene.h"
#include "bibGameObject.h"
#include "bibPlayer.h"
#include "bibTransform.h"
#include "bibSpriteRenderer.h"
#include "bibInput.h"
#include "bibTitleScene.h"
#include "bibSceneManager.h"
#include "bibObject.h"

namespace bib
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"D:\\GitHub\\Test\\Window_Editor\\Window_Test\\CloudOcean.png");

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//transform* tr = bg->getcomponent<transform>();
		//tr->setpos(vector2(0, 0));
	}
}