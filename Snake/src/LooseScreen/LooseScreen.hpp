#pragma once

#include "LooseScreenUi.hpp"

namespace jp
{
	class LooseScreenState
	{
	public:
		LooseScreenState(Game &p_GameRef);
		~LooseScreenState();

	public:
		void onInit();
		void onInput(sf::Event &p_EventRef);
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);
		void onWindowResize();

	private:
		LooseScreenUi m_LooseScreenUi;

	private:
		Game *m_GamePtr{nullptr};
		Window *m_WindowPtr{nullptr};
	};

}