#include "Grid.hpp"

#include "Random.hpp"

namespace jp
{

	Grid::Grid(sf::Vector2f p_GridOffset, sf::Vector2f p_GridSize, sf::Vector2f p_GridTileSize) {
		m_GridSize = p_GridSize;
		m_GridOffset = p_GridOffset;
		m_GridTileSize = p_GridTileSize;
		this->makeGrid();
	}

	sf::Vector2f Grid::getRandomPositionInGrid() {
		sf::Vector2f _newRandomPosition(m_GridTileCenterPoints.at(Random::getRandomBetween<int>(1, (int)m_GridTileCenterPoints.size())));
		return sf::Vector2f(_newRandomPosition.x + m_GridOffset.x, _newRandomPosition.y + m_GridOffset.y);
	}

	void Grid::makeGrid() {
		int _XTileCount = (int)(m_GridSize.x / m_GridTileSize.x);
		int _YTileCount = (int)(m_GridSize.y / m_GridTileSize.y);
		for (size_t jt = 0; jt < _YTileCount; jt++)
		{
			for (size_t it = 0; it < _XTileCount; it++)
			{
				m_GridTileCenterPoints.push_back(sf::Vector2f((it * m_GridTileSize.x) + (m_GridTileSize.x / 2), (jt * m_GridTileSize.y) + (m_GridTileSize.y / 2)));
			}
		}
	}

}