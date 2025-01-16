#pragma once
#include "CommonInclude.h"
namespace bib
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		//void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);	
		void SetPosition(float x, float y)
		{
			axisX = x;
			axisY = y;
		}

		float GetPositionX() { return axisX; }
		float GetPositionY() { return axisY; }

	private:
		float axisX = 0.0f;
		float axisY = 0.0f;
	};
}