#pragma once

#include "MainMenuUi.hpp"

namespace jp
{
	class Game;
	class Window;
	class MainMenustate
	{
	public:
		MainMenustate(Game &p_GameRef);
		~MainMenustate();

	public:
		void onInit();
		void onInput(sf::Event &p_EventRef);
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);
		void onWindowResize();

	private:
		MainMenuUi m_MainMenuUi;

	private:
		Game *m_GamePtr{nullptr};
		Window *m_WindowPtr{nullptr};

	};

}