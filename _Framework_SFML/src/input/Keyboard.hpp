#pragma once

namespace jp
{

	class Keyboard
	{
	public:
		struct KeyState
		{
			bool m_Down;
			bool m_Pressed;
			bool m_Released;
		};

	public:
		static bool KeyPressed(int p_Key);
		static bool KeyDown(int p_Key);

	private:
		static KeyState m_KeyState[256];

	};

}