#include "bibGameObject.h"
#include "bibInput.h"
#include "bibTime.h"
namespace bib
{
	GameObject::GameObject()
		: axisX(0)
		, axisY(0)
	{

	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			axisX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			axisX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			axisY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			axisY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);
		//Rectangle(hdc, axisX, axisY, 100 + axisX, 100 + axisY);
		//SelectObject(hdc, oldBrush);
		Ellipse(hdc, axisX, axisY, 100 + axisX, 100 + axisY);
		DeleteObject(redPen);
		DeleteObject(blueBrush);
	}
}