#include "bibInput.h"
namespace bib
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initialize()
	{

		//typedef int DOGUEINT;

		//DOGUEINT a = 0;
		mKeys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.isPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].isPressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				else
				{
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].isPressed = true;
			}
			else
			{
				if (mKeys[i].isPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				else
				{
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].isPressed = false;
			}
		}
	}
}

