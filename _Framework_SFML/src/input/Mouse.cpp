#include "Mouse.hpp"

#include <Windows.h>

namespace jp
{

	Mouse::KeyState Mouse::m_KeyState[] = {};

	bool Mouse::KeyPressed(int p_Key) {
		if (GetKeyState(p_Key) & 0x80)
		{
			if (Mouse::m_KeyState[p_Key].m_Released)
			{
				Mouse::m_KeyState[p_Key].m_Released = false;
			}
			if (Mouse::m_KeyState[p_Key].m_Pressed)
			{
				Mouse::m_KeyState[p_Key].m_Down = true;
			}
			if (GetKeyState(p_Key) & 0x80 && !Mouse::m_KeyState[p_Key].m_Down)
			{
				Mouse::m_KeyState[p_Key].m_Pressed = true;
				return true;
			}
			return false;
		}
		if (!Mouse::m_KeyState[p_Key].m_Released)
		{
			Mouse::m_KeyState[p_Key].m_Released = true;
			Mouse::m_KeyState[p_Key].m_Down = false;
			Mouse::m_KeyState[p_Key].m_Pressed = false;
		}
		return false;
	}

	bool Mouse::KeyDown(int p_Key) {
		return GetKeyState(p_Key) & 0x8000;
	}

	sf::Vector2f Mouse::getMousePosition() {
		HWND _windowHandle = GetActiveWindow();
		POINT _mousePosition;
		GetCursorPos(&_mousePosition);
		ScreenToClient(_windowHandle, &_mousePosition);
		return sf::Vector2f((float)_mousePosition.x, (float)_mousePosition.y);
	}

}