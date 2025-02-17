#include "bibPlayScene.h"
#include "bibGameObject.h"
#include "bibPlayer.h"
#include "bibTransform.h"
#include "bibSpriteRenderer.h"
#include "bibInput.h"
#include "bibTitleScene.h"
#include "bibSceneManager.h"
#include "bibObject.h"
#include "bibTexture.h"
#include "bibResources.h"
#include "bibPlayerScript.h"
#include "bibCamera.h"
#include "bibRenderer.h"

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

		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();
		mPlayer = object::Instantiate<Player>
			(enums::eLayerType::Player/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();
		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"PackMan");
		sr->SetTexture(packmanTexture);
		GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);

		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
		bgSr->SetTexture(bgTexture);

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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
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