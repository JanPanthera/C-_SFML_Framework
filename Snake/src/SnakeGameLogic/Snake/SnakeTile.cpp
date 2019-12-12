#include "SnakeTile.hpp"

namespace jp
{
	SnakeTile::SnakeTile(sf::Vector2f p_SnakeTilePosition, sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor) :
		m_ParentSnakeTilePtr(nullptr),
		m_SnakeTileLastPosition(),
		m_SnakeTileSize(p_SnakeTileSize) {

		m_SnakeTileShape.setFillColor(p_SnakeTileColor);
		m_SnakeTileShape.setPosition(p_SnakeTilePosition);
		m_SnakeTileShape.setSize(p_SnakeTileSize);
	}

	SnakeTile::SnakeTile(sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor, SnakeTile *p_ParentSnakeTilePtr) :
		m_ParentSnakeTilePtr(p_ParentSnakeTilePtr),
		m_SnakeTileLastPosition(p_ParentSnakeTilePtr->getSnakeTilePosition()),
		m_SnakeTileSize(p_SnakeTileSize) {

		m_SnakeTileShape.setFillColor(p_SnakeTileColor);
		m_SnakeTileShape.setPosition(p_ParentSnakeTilePtr->getSnakeTilePosition());
		m_SnakeTileShape.setSize(p_SnakeTileSize);
	}

	SnakeTile::SnakeTile(sf::Vector2f p_SnakeTilePosition, sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor, SnakeTile *p_ParentSnakeTilePtr) :
		m_ParentSnakeTilePtr(p_ParentSnakeTilePtr),
		m_SnakeTileLastPosition(p_SnakeTilePosition),
		m_SnakeTileSize(p_SnakeTileSize) {

		m_SnakeTileShape.setFillColor(p_SnakeTileColor);
		m_SnakeTileShape.setPosition(p_SnakeTilePosition);
		m_SnakeTileShape.setSize(p_SnakeTileSize);
	}

	SnakeTile::~SnakeTile() {
		m_ParentSnakeTilePtr = nullptr;
	}

	void SnakeTile::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		p_RenderWindowRef.draw(m_SnakeTileShape);
	}

	bool SnakeTile::hitsCenterPosSnakeTile(sf::Vector2f p_CenterPositionToCheckTheHit) const {
		if (p_CenterPositionToCheckTheHit.x > m_SnakeTileShape.getGlobalBounds().left and
			p_CenterPositionToCheckTheHit.x < m_SnakeTileShape.getGlobalBounds().left + m_SnakeTileShape.getGlobalBounds().width and
			p_CenterPositionToCheckTheHit.y > m_SnakeTileShape.getGlobalBounds().top and
			p_CenterPositionToCheckTheHit.y < m_SnakeTileShape.getGlobalBounds().top + m_SnakeTileShape.getGlobalBounds().height)
		{
			return true;
		}
		return false;
	}

	sf::Vector2f SnakeTile::getSnakeBodyCenterPosition() const {
		return sf::Vector2f(m_SnakeTileShape.getGlobalBounds().left + m_SnakeTileShape.getGlobalBounds().width / 2,
							m_SnakeTileShape.getGlobalBounds().top + m_SnakeTileShape.getGlobalBounds().height / 2);
	}

	void SnakeTile::setPosition(sf::Vector2f p_NewPosition) {
		m_SnakeTileLastPosition = m_SnakeTileShape.getPosition();
		m_SnakeTileShape.setPosition(p_NewPosition);
	}

	sf::Vector2f SnakeTile::getSnakeTileSize() const {
		return m_SnakeTileSize;
	}

	sf::Vector2f SnakeTile::getSnakeTilePosition() const {
		return m_SnakeTileShape.getPosition();
	}

	sf::Vector2f SnakeTile::getSnakeTileLastPosition() const {
		return m_SnakeTileLastPosition;
	}

}