#pragma once
#include "..\\Win_SOURCE\\bibScene.h"
namespace bib
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}