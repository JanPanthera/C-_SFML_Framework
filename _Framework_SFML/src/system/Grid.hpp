#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>

namespace jp
{

	class Grid
	{
	public:
		Grid(sf::Vector2f p_GridOffset, sf::Vector2f p_GridSize, sf::Vector2f p_GridTileSize);

	public:
		sf::Vector2f getRandomPositionInGrid();

	private:
		void makeGrid();

	private:
		sf::Vector2f m_GridSize;
		sf::Vector2f m_GridOffset;
		sf::Vector2f m_GridTileSize;
		std::vector<sf::Vector2f> m_GridTileCenterPoints;

	};

}