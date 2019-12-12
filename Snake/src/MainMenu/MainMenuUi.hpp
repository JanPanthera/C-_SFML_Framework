#pragma once

#include <gui/Text.hpp>
#include <gui/TextBtn.hpp>

namespace jp
{

	class Game;
	class MainMenuUi
	{
	public:
		MainMenuUi(Game &p_GameRef);
		~MainMenuUi();

	public:
		void onInit();
		void onInput(sf::Event &p_EventRef);
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);
		void onWindowResize();

	private:
		void initializeButtons();

	private:
		float m_ButtonFontSize{136.f};
		float m_PaddingBetweenButtons{50.f};
		float m_PaddingFromWindowBottom{100.f};

	private:
		Game *m_GamePtr{nullptr};
		Window *m_WindowPtr{nullptr};

	private:
		Text m_GameNameText;

		TextBtn m_StartGameBtn;
		TextBtn m_OptionsBtn;
		TextBtn m_QuitBtn;

	};

}