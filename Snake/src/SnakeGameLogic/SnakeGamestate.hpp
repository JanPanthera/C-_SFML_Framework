#pragma once

#include <system/Grid.hpp>
#include <gui/Text.hpp>

#include "Snake/Snake.hpp"
#include "Coin.hpp"

namespace jp
{
	class Game;
	class Window;
	class SnakeGamestate
	{
	public:
		SnakeGamestate(Game &p_GameRef);
		~SnakeGamestate();

	public:
		void onInput(sf::Event &p_EventRef);
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);
		void onWindowResize();

	private:
		void InitializeText();
		void Input(sf::Event &p_EventRef);
		void Update(double p_ElapsedTime);
		void UpdateDebugText();

	private:
		bool m_CoinPositioned{false};

	private:
		float m_TickRate{0.4f};
		sf::Vector2f m_SnakeTileSize{30.f, 30.f};

	private:
		sf::Clock m_TickClock;

	private:
		Text m_DebugText;

	private:
		Coin *m_CoinPtr{nullptr};
		Grid *m_GridPtr{nullptr};
		Game *m_GamePtr{nullptr};
		Snake *m_SnakePtr{nullptr};
		Window *m_WindowPtr{nullptr};

	};

}