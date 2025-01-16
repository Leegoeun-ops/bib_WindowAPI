#pragma once
#include "CommonInclude.h"
namespace bib
{
	enum class eKeyState
	{
		NONE,
		DOWN,
		PRESSED,
		UP
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool isPressed;
		};

		static void Initialize();

		static void Update();

		static bool GetKeyDown(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::DOWN; }
		static bool GetKeyUp(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::UP; }
		static bool GetKey(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::PRESSED; }

	private:
		static std::vector<Key> mKeys;
	};

}

