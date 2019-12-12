#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

namespace jp
{

	class SnakeTile
	{
	public:


	public:
		SnakeTile(sf::Vector2f p_SnakeTilePosition, sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor);
		SnakeTile(sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor, SnakeTile *p_ParentSnakeTilePtr);
		SnakeTile(sf::Vector2f p_SnakeTilePosition, sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor, SnakeTile *p_ParentSnakeTilePtr);
		~SnakeTile();

	protected:
		void onDraw(sf::RenderWindow &p_RenderWindowRef);

	public:
		bool hitsCenterPosSnakeTile(sf::Vector2f p_CenterPositionToCheckTheHit) const;

	public:
		sf::Vector2f getSnakeBodyCenterPosition() const;

	public:
		void setPosition(sf::Vector2f p_NewPosition);

	public:
		sf::Vector2f getSnakeTileSize() const;
		sf::Vector2f getSnakeTilePosition() const;
		sf::Vector2f getSnakeTileLastPosition() const;

	protected:
		SnakeTile *m_ParentSnakeTilePtr{nullptr};

	private:
		sf::RectangleShape m_SnakeTileShape;
		sf::Vector2f m_SnakeTileSize{10.f, 10.f};
		sf::Vector2f m_SnakeTileLastPosition{-100.f, -100.f};

	};

}