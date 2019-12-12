#pragma once

#include <vector>

#include "SnakeHead.hpp"
#include "SnakeBody.hpp"

namespace jp
{
	class Snake
	{
	public:
		Snake(sf::Vector2f p_SnakeSize, sf::Color p_SnakeHeadColor, sf::Color p_SnakeBodyColor);
		~Snake();

	public:
		void onInput(sf::Event &p_Event);
		void onTick(double p_ElapsedTime);
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);

	public:
		void setSnakeInitialPosition(sf::Vector2f p_Position);

	public:
		sf::Vector2f getSnakeHeadPosition() const;

	public:
		void addBodyTile();

	public:
		bool hitsSnakeHeadTile(sf::Vector2f p_CenterPositionToCheckTheHit) const;
		bool hitsSnakeBodyTile() const;
		bool hitsWindowBorder(sf::FloatRect p_WindowBorderRect) const;

	private:
		sf::Vector2f m_SnakeTileSizeVec;

	private:
		SnakeHead m_SnakeHead;

	private:
		sf::Color m_SnakeBodyColor;
		std::vector<SnakeBody *> m_SnakeBodyTiles;

	};
}