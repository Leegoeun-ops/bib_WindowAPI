#pragma once
#include "..\\Win_SOURCE\\bibScript.h"
namespace bib
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}