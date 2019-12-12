#include "SnakeHead.hpp"

#include <system/Random.hpp>
#include <input/Keyboard.hpp>

namespace jp
{

	SnakeHead::SnakeHead(sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor) :
		SnakeTile(sf::Vector2f(-100.f, -100.f), p_SnakeTileSize, p_SnakeTileColor),
		m_SnakeTileDirection((Direction)Random::getRandomBetween<unsigned int>(0, 3)) {
	}

	void SnakeHead::onInput(sf::Event &p_Event) {
		if (Keyboard::KeyPressed('W'))
		{
			changeDirection(SnakeHead::Direction::UP);
		}
		if (Keyboard::KeyPressed('S'))
		{
			changeDirection(SnakeHead::Direction::DOWN);
		}
		if (Keyboard::KeyPressed('A'))
		{
			changeDirection(SnakeHead::Direction::LEFT);
		}
		if (Keyboard::KeyPressed('D'))
		{
			changeDirection(SnakeHead::Direction::RIGHT);
		}
	}

	void SnakeHead::onTick(double p_ElapsedTime) {
		this->updatePosition();
	}

	void SnakeHead::onUpdate(double p_ElapsedTime) {
	}

	void SnakeHead::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		SnakeTile::onDraw(p_RenderWindowRef);
	}

	void SnakeHead::changeDirection(Direction p_NewDirection) {
		switch (p_NewDirection)
		{
		case Direction::UP:
			if (m_SnakeTileDirection != Direction::DOWN)
			{
				m_SnakeTileDirection = p_NewDirection;
			}
			break;
		case Direction::DOWN:
			if (m_SnakeTileDirection != Direction::UP)
			{
				m_SnakeTileDirection = p_NewDirection;
			}
			break;
		case Direction::LEFT:
			if (m_SnakeTileDirection != Direction::RIGHT)
			{
				m_SnakeTileDirection = p_NewDirection;
			}
			break;
		case Direction::RIGHT:
			if (m_SnakeTileDirection != Direction::LEFT)
			{
				m_SnakeTileDirection = p_NewDirection;
			}
			break;
		default:
			break;
		}
	}

	void SnakeHead::updatePosition() {
		switch (m_SnakeTileDirection)
		{
		case Direction::UP:
			SnakeTile::setPosition(sf::Vector2f(SnakeTile::getSnakeTilePosition().x, SnakeTile::getSnakeTilePosition().y - SnakeTile::getSnakeTileSize().y));
			break;
		case Direction::DOWN:
			SnakeTile::setPosition(sf::Vector2f(SnakeTile::getSnakeTilePosition().x, SnakeTile::getSnakeTilePosition().y + SnakeTile::getSnakeTileSize().y));
			break;
		case Direction::LEFT:
			SnakeTile::setPosition(sf::Vector2f(SnakeTile::getSnakeTilePosition().x - SnakeTile::getSnakeTileSize().x, SnakeTile::getSnakeTilePosition().y));
			break;
		case Direction::RIGHT:
			SnakeTile::setPosition(sf::Vector2f(SnakeTile::getSnakeTilePosition().x + SnakeTile::getSnakeTileSize().x, SnakeTile::getSnakeTilePosition().y));
			break;
		default:
			break;
		}
	}

}