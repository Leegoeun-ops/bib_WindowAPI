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

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			axisX -= 0.001f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			axisX += 0.001f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			axisY -= 0.001f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			axisY += 0.001f;
		}
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		// TODO: 여기에 mHdc를 사용하는 그리기 코드를 추가합니다...
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
		SelectObject(mHdc, oldPen);

		Rectangle(mHdc, 100 + axisX, 100 + axisY, 200 + axisX, 200 + axisY);

		SelectObject(mHdc, oldBrush);
		DeleteObject(redPen);
		DeleteObject(blueBrush);
	}
}