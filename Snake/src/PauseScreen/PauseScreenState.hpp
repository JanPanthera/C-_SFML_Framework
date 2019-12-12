#pragma once

#include "PauseScreenUi.hpp"

namespace jp
{
	class Game;
	class Window;
	class PauseScreenState
	{
	public:
		PauseScreenState(Game &p_GameRef);
		~PauseScreenState();

	public:
		void onInit();
		void onInput(sf::Event &p_EventRef);
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);
		void onWindowResize();

	private:
		PauseScreenUi m_PauseScreenUi;

	private:
		Game *m_GamePtr{nullptr};
		Window *m_WindowPtr{nullptr};

	};

}