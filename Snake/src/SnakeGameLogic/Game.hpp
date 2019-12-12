#pragma once

#include <system/Framework.hpp>
#include <system/LogToFile.hpp>
#include <Defines.hpp>

#include "../MainMenu/MainMenustate.hpp"
#include "../PauseScreen/PauseScreenState.hpp"
#include "../LooseScreen/LooseScreen.hpp"
#include "SnakeGamestate.hpp"

namespace jp
{

	enum class Gamestates
	{
		MainMenu = 0,
		SnakeGame = 1,
		PauseScreen = 2,
		LooseScreen = 3
	};

	class Game : public Framework
	{
	public:
		Game();
		~Game();

	public:
		virtual bool onInit() override;
		virtual void onInput(sf::Event &p_EventRef) override;
		virtual void onUpdate(double p_ElapsedTime) override;
		virtual void onDraw(sf::RenderWindow &p_RenderWindowRef) override;
		virtual void onWindowResize() override;

	public:
		void restart();
		void changeGameState(Gamestates p_GameState);

	public:
		Window &getWindowRef() const;

	private:
		bool initWindow();
		bool initGamestates();

	private:
		bool m_Fullscreen{false};

	private:
		Window *m_WindowPtr{nullptr};
		LooseScreenState *m_LooseScreenPtr{nullptr};
		MainMenustate *m_MainMenustatePtr{nullptr};
		SnakeGamestate *m_SnakeGamestatePtr{nullptr};
		PauseScreenState *m_PauseScreenStatePtr{nullptr};

	private:
		Gamestates m_GameStates{Gamestates::MainMenu};

	};

}