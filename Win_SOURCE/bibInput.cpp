#include "bibInput.h"

namespace bib
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
	};

	void Input::Initialize()
	{
		//typedef int DOGUEINT;
		//DOGUEINT a = 0;

		for (size_t i = 0; (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.isPressed = false;
			key.state = eKeyState::NONE;
			key.keyCode = (eKeyCode)i;
			mKeys.push_back(key);
		}
	}
	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)//pressed
			{
				//이전 프레임에서 눌러져있고 지금도 눌렀다.
				if (mKeys[i].isPressed == true)
					mKeys[i].state = eKeyState::PRESSED;
				else
					mKeys[i].state = eKeyState::DOWN;

				mKeys[i].isPressed = true;
			}
			else
			{
				if (mKeys[i].isPressed == true)
					mKeys[i].state = eKeyState::UP;
				else
					mKeys[i].state = eKeyState::NONE;

				mKeys[i].isPressed = false;

			}
		}
	}
}

