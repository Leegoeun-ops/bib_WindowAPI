#include "bibGameObject.h"
#include "bibInput.h"
namespace bib
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			axisX -= 0.001f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			axisX += 0.001f;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			axisY -= 0.001f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			axisY += 0.001f;
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);
		Rectangle(hdc, 100 + axisX, 100 + axisY, 200 + axisX, 200 + axisY);
		SelectObject(hdc, oldBrush);
		DeleteObject(redPen);
		DeleteObject(blueBrush);
	}
}