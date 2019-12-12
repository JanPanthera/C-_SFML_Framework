#pragma once

#include <SFML/System/Vector2.hpp>

namespace jp
{

	class Mouse
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

	public:
		static sf::Vector2f getMousePosition();

	private:
		static KeyState m_KeyState[256];

	};

}