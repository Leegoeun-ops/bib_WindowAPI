#pragma once
#include "CommonInclude.h"

namespace bib
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

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
		float axisX;
		float axisY;
	};

}
