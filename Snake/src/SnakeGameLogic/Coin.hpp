#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

namespace jp
{

	class Coin
	{
	public:
		Coin(sf::Vector2f p_CoinPos, sf::Vector2f p_CoinSize, sf::Color p_CoinColor);
		~Coin();

	public:
		void onDraw(sf::RenderWindow &p_RenderWindowRef);

	public:
		void setPosition(sf::Vector2f p_NewPosition);

	public:
		sf::Vector2f getCoinCenterPosition() const;

	private:
		sf::RectangleShape m_CoinShape;

	};

}