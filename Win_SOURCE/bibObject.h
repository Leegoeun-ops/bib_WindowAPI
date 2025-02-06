#pragma once
#include "bibComponent.h"
#include "bibGameObject.h"
#include "bibLayer.h"
#include "bibScene.h"
#include "bibSceneManager.h"
#include "bibTransform.h"
namespace bib::object
{
	template <typename T>
	static T* Instantiate(bib::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		return gameObject;
	}
	template <typename T>
	static T* Instantiate(bib::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);
		return gameObject;
	}
}