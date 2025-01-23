#include "bibTime.h"

namespace bib
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		//cpu frequency
		QueryPerformanceFrequency(&CpuFrequency);

		//프로그램이 시작했을 때 진동 수
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;
		//char str2 = 'A';
		wchar_t str[50] = L"";
		swprintf_s(str, 50,  L"Time : %d", (int)fps);

		int len = wcsnlen_s(str, 50);

		//std::wcstoul
		TextOut(hdc, 0, 0, str, len);//wsprintf(str, L"Time : %f", time)
	}
}
