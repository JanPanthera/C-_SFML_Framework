#include "Coin.hpp"

namespace jp
{

	Coin::Coin(sf::Vector2f p_CoinPos, sf::Vector2f p_CoinSize, sf::Color p_CoinColor) {
		m_CoinShape.setPosition(p_CoinPos);
		m_CoinShape.setSize(p_CoinSize);
		m_CoinShape.setFillColor(p_CoinColor);
	}

	Coin::~Coin() {
	}

	void Coin::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		p_RenderWindowRef.draw(m_CoinShape);
	}

	void Coin::setPosition(sf::Vector2f p_NewPosition) {
		m_CoinShape.setPosition(p_NewPosition);
	}

	sf::Vector2f Coin::getCoinCenterPosition() const {
		return sf::Vector2f(m_CoinShape.getGlobalBounds().left + m_CoinShape.getGlobalBounds().width / 2,
							m_CoinShape.getGlobalBounds().top + m_CoinShape.getGlobalBounds().height / 2);
	}

}