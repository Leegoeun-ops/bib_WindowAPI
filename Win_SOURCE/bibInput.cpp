#include "bibInput.h"
namespace bib
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,

	};

	void Input::Initialize()
	{

		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(), 
			[](Key& key) -> void
			{ 
				updateKey(key);
			});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}

	bool Input::isKeyDown(eKeyCode key)
	{
		return GetAsyncKeyState(ASCII[(UINT)key]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if(key.isPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;
		
		key.isPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.isPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.isPressed = true;
	}

	void Input::createKeys()
	{
		//typedef int DOGUEINT;

		//DOGUEINT a = 0;
		//mKeys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.isPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}
}

