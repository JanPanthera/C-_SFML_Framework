#pragma once

#include "SnakeTile.hpp"

namespace jp
{

	class SnakeHead : public SnakeTile
	{
	public:
		enum class Direction
		{
			UP = 0,
			DOWN = 1,
			LEFT = 2,
			RIGHT = 3
		};

	public:
		SnakeHead(sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor);

	public:
		void onInput(sf::Event &p_Event);
		void onTick(double p_ElapsedTime);
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);

	private:
		void changeDirection(Direction p_NewDirection);
		void updatePosition();

	private:
		Direction m_SnakeTileDirection{Direction::RIGHT};

	};


}