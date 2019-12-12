#pragma once

#include "SnakeTile.hpp"

namespace jp
{

	class SnakeBody : public SnakeTile
	{
	public:
		SnakeBody(sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor, SnakeTile *p_ParentSnakeTilePtr);
		SnakeBody(sf::Vector2f p_SnakeTilePosition, sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor, SnakeTile *p_ParentSnakeTilePtr);

	public:
		void onTick(double p_ElapsedTime);
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);

	private:
		void updatePosition();

	};

}