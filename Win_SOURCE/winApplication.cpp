#include "winApplication.h"
#include "bibInput.h"
#include "bibTime.h"
#include "bibSceneManager.h"
namespace bib 
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{
		
	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		SceneManager::Initialize();
		/*for (size_t i = 0; i < 100; i++) {
			GameObject* gameObj = new GameObject();

			gameObj->SetPosition(rand() % 1600, rand() % 900);
			mGameObjects.push_back(gameObj);
		}*/
		
		//mPlayer.SetPosition(0, 0);

	}
	void Application::Run() 
	{
		//m += 1;
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();
		SceneManager::Update();
		/*for (size_t i = 0; i < mGameObjects.size(); i++) {
			mGameObjects[i]->Update();
		}*/
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		clearRenderTarget();
		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		/*for (size_t i = 0; i < mGameObjects.size(); i++) {
			mGameObjects[i]->Render(mBackHdc);
		}*/
		copyRenderTarget(mBackHdc, mHdc);
		//BackBuffer에 있는 그림을 화면에 복사
	}

	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);

	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0,width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}