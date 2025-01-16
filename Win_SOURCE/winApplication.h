#pragma once
#include "bibGameObject.h"
#include "CommonInclude.h"
namespace bib {
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;

		//float mSpeed;
		//float axisX;
		//float axisY;

		GameObject mPlayer;
	};

}
