#include "Keyboard.hpp"

#include <Windows.h>

namespace jp
{

	Keyboard::KeyState Keyboard::m_KeyState[] = {};

	bool Keyboard::KeyPressed(int p_Key) {
		if (GetKeyState(p_Key) & 0x8000)
		{
			if (Keyboard::m_KeyState[p_Key].m_Released)
			{
				Keyboard::m_KeyState[p_Key].m_Released = false;
			}
			if (Keyboard::m_KeyState[p_Key].m_Pressed)
			{
				Keyboard::m_KeyState[p_Key].m_Down = true;
			}
			if (GetKeyState(p_Key) & 0x8000 && !Keyboard::m_KeyState[p_Key].m_Down)
			{
				Keyboard::m_KeyState[p_Key].m_Pressed = true;
				return true;
			}
			return false;
		}
		if (!Keyboard::m_KeyState[p_Key].m_Released)
		{
			Keyboard::m_KeyState[p_Key].m_Released = true;
			Keyboard::m_KeyState[p_Key].m_Down = false;
			Keyboard::m_KeyState[p_Key].m_Pressed = false;
		}
		return false;
	}

	bool Keyboard::KeyDown(int p_Key) {
		return GetKeyState(p_Key) & 0x8000;
	}

}