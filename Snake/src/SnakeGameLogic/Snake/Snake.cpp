#include "Snake.hpp"

#include <system/LogToFile.hpp>
#include <Defines.hpp>

namespace jp
{

	Snake::Snake(sf::Vector2f p_SnakeSize, sf::Color p_SnakeHeadColor, sf::Color p_SnakeBodyColor) :
		m_SnakeTileSizeVec(p_SnakeSize),
		m_SnakeBodyColor(p_SnakeBodyColor),
		m_SnakeHead(p_SnakeSize, p_SnakeHeadColor) {
	}

	Snake::~Snake() {
		for (int it = 0; it < m_SnakeBodyTiles.size(); it++)
		{
			delete m_SnakeBodyTiles.at(it);
		}
	}

	void Snake::onInput(sf::Event &p_Event) {
		m_SnakeHead.onInput(p_Event);
	}

	void Snake::onTick(double p_ElapsedTime) {
		m_SnakeHead.onTick(p_ElapsedTime);
		if (m_SnakeBodyTiles.size() > 0)
		{
			for (auto &SnakeBodyTile : m_SnakeBodyTiles)
			{
				SnakeBodyTile->onTick(p_ElapsedTime);
			}
		}
	}

	void Snake::onUpdate(double p_ElapsedTime) {
		m_SnakeHead.onUpdate(p_ElapsedTime);
		if (m_SnakeBodyTiles.size() > 0)
		{
			for (auto &SnakeBodyTile : m_SnakeBodyTiles)
			{
				SnakeBodyTile->onUpdate(p_ElapsedTime);
			}
		}
	}

	void Snake::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		m_SnakeHead.onDraw(p_RenderWindowRef);
		if (m_SnakeBodyTiles.size() > 0)
		{
			for (auto &SnakeBodyTile : m_SnakeBodyTiles)
			{
				SnakeBodyTile->onDraw(p_RenderWindowRef);
			}
		}
	}

	void Snake::setSnakeInitialPosition(sf::Vector2f p_Position) {
		m_SnakeHead.setPosition(p_Position);
	}

	sf::Vector2f Snake::getSnakeHeadPosition() const {
		return m_SnakeHead.getSnakeTilePosition();
	}

	void Snake::addBodyTile() {
		if (m_SnakeBodyTiles.size() == 0)
		{
			SnakeBody *_Body = new SnakeBody(m_SnakeHead.getSnakeTileLastPosition(), m_SnakeTileSizeVec, m_SnakeBodyColor, &m_SnakeHead);
			m_SnakeBodyTiles.push_back(_Body);
		}
		else if (m_SnakeBodyTiles.size() > 0)
		{
			SnakeBody *_Body = new SnakeBody(m_SnakeTileSizeVec, m_SnakeBodyColor, m_SnakeBodyTiles.at(m_SnakeBodyTiles.size() - 1));
			m_SnakeBodyTiles.push_back(_Body);
		}
	}

	bool Snake::hitsSnakeHeadTile(sf::Vector2f p_CenterPositionToCheckTheHit) const {
		return m_SnakeHead.hitsCenterPosSnakeTile(p_CenterPositionToCheckTheHit);
	}

	bool Snake::hitsSnakeBodyTile() const {
		bool _snakeHitsBodyTile = false;
		for (auto &_SnakeBodyTile : m_SnakeBodyTiles)
		{
			if (m_SnakeHead.hitsCenterPosSnakeTile(_SnakeBodyTile->getSnakeBodyCenterPosition()))
			{
				_snakeHitsBodyTile = true;
				break;
			}
		}
		return _snakeHitsBodyTile;
	}

	bool Snake::hitsWindowBorder(sf::FloatRect p_WindowBorderRect) const {
		if (m_SnakeHead.getSnakeTilePosition().x < p_WindowBorderRect.left or
			m_SnakeHead.getSnakeTilePosition().y < p_WindowBorderRect.top or
			m_SnakeHead.getSnakeTilePosition().x > p_WindowBorderRect.width or
			m_SnakeHead.getSnakeTilePosition().y > p_WindowBorderRect.height)
		{
			return true;
		}
		return false;
	}

}