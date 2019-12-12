#include "SnakeBody.hpp"

namespace jp
{

	SnakeBody::SnakeBody(sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor, SnakeTile *p_ParentSnakeTilePtr) :
		SnakeTile(p_SnakeTileSize, p_SnakeTileColor, p_ParentSnakeTilePtr) {
	}

	SnakeBody::SnakeBody(sf::Vector2f p_SnakeTilePosition, sf::Vector2f p_SnakeTileSize, sf::Color p_SnakeTileColor, SnakeTile *p_ParentSnakeTilePtr) :
		SnakeTile(p_SnakeTilePosition, p_SnakeTileSize, p_SnakeTileColor, p_ParentSnakeTilePtr) {
	}

	void SnakeBody::onTick(double p_ElapsedTime) {
		this->updatePosition();
	}

	void SnakeBody::onUpdate(double p_ElapsedTime) {
	}

	void SnakeBody::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		SnakeTile::onDraw(p_RenderWindowRef);
	}

	void SnakeBody::updatePosition() {
		SnakeTile::setPosition(m_ParentSnakeTilePtr->getSnakeTileLastPosition());
	}

}