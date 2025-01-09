#include "winApplication.h"

namespace bib 
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, axisX(0.0f)
		, axisY(0.0f)
	{
		
	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void Application::Run() 
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mSpeed += 0.001f;
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		// TODO: 여기에 mHdc를 사용하는 그리기 코드를 추가합니다...
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		//HPEN redpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldpen = (HPEN)SelectObject(mHdc, redpen);

		Rectangle(mHdc, 100 + mSpeed, 100, 200 + mSpeed, 200);

		SelectObject(mHdc, oldBrush);
		//DeleteObject(redpen);
		DeleteObject(blueBrush);
	}
}