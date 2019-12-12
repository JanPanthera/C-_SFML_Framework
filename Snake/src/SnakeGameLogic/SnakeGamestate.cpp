#include "SnakeGamestate.hpp"

#include <system/LogToFile.hpp>
#include <input/Keyboard.hpp>
#include <Defines.hpp>

#include "../SnakeGameLogic/Game.hpp"

namespace jp
{

	SnakeGamestate::SnakeGamestate(Game &p_GameRef) :
		m_TickClock(),
		m_DebugText(p_GameRef.getWindowRef(), DEFAULT_FONT) {

		m_GamePtr = &p_GameRef;
		m_WindowPtr = &p_GameRef.getWindowRef();

		m_SnakePtr = new Snake(m_SnakeTileSize, sf::Color::Cyan, sf::Color::Red);
		m_GridPtr = new Grid(sf::Vector2f((float)m_WindowPtr->getWindowInformations().s_WindowViewPos.x,
										  (float)m_WindowPtr->getWindowInformations().s_WindowViewPos.y),
							 sf::Vector2f((float)m_WindowPtr->getWindowInformations().s_WindowViewSize.x,
										  (float)m_WindowPtr->getWindowInformations().s_WindowViewSize.y), m_SnakeTileSize);
		sf::Vector2f _RandomPosForCoin = m_GridPtr->getRandomPositionInGrid();
		m_CoinPtr = new Coin(sf::Vector2f(_RandomPosForCoin.x - m_SnakeTileSize.x / 2, _RandomPosForCoin.y - m_SnakeTileSize.y / 2), m_SnakeTileSize, sf::Color::Yellow);
		m_CoinPositioned = true;

		this->InitializeText();

		sf::Vector2f _RandomPosForSnake = m_GridPtr->getRandomPositionInGrid();
		m_SnakePtr->setSnakeInitialPosition(sf::Vector2f(_RandomPosForSnake.x - m_SnakeTileSize.x / 2, _RandomPosForSnake.y - m_SnakeTileSize.y / 2));
		m_SnakePtr->addBodyTile();
	}

	SnakeGamestate::~SnakeGamestate() {
		delete m_CoinPtr;
		delete m_GridPtr;
		delete m_SnakePtr;
		m_GamePtr = nullptr;
		m_WindowPtr = nullptr;
	}

	void SnakeGamestate::onInput(sf::Event &p_EventRef) {
		this->Input(p_EventRef);
		m_SnakePtr->onInput(p_EventRef);
	}

	void SnakeGamestate::onUpdate(double p_ElapsedTime) {
		this->UpdateDebugText();
		this->Update(p_ElapsedTime);
		m_SnakePtr->onUpdate(p_ElapsedTime);
		if (m_TickClock.getElapsedTime().asSeconds() > 1.0f * m_TickRate)
		{
			m_SnakePtr->onTick(p_ElapsedTime);
			m_TickClock.restart();
		}
	}

	void SnakeGamestate::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		m_CoinPtr->onDraw(p_RenderWindowRef);
		m_SnakePtr->onDraw(p_RenderWindowRef);
		m_DebugText.onDraw(p_RenderWindowRef);
	}

	void SnakeGamestate::onWindowResize() {

	}

	void SnakeGamestate::InitializeText() {
		m_DebugText.setFontSize(40);
		m_DebugText.setTextString("test");
		m_DebugText.setTextColor(sf::Color(0, 0, 250, 255));
		m_DebugText.setPosition(sf::Vector2f(50.f, 100.f));
	}

	void SnakeGamestate::Input(sf::Event &p_EventRef) {
		if (Keyboard::KeyPressed(KEY_ESCAPE))
		{
			m_GamePtr->changeGameState(Gamestates::PauseScreen);
		}
		if (Keyboard::KeyPressed('T'))
		{
			m_SnakePtr->addBodyTile();
		}
	}

	void SnakeGamestate::Update(double p_ElapsedTime) {
		if (m_SnakePtr->hitsWindowBorder(m_WindowPtr->getWindowViewAsFloatRect()))
		{
			m_GamePtr->changeGameState(Gamestates::LooseScreen);
		}
		if (m_SnakePtr->hitsSnakeBodyTile())
		{
			m_GamePtr->changeGameState(Gamestates::LooseScreen);
		}
		if (m_SnakePtr->hitsSnakeHeadTile(m_CoinPtr->getCoinCenterPosition()))
		{
			m_SnakePtr->addBodyTile();
			m_CoinPositioned = false;
		}
		if (!m_CoinPositioned)
		{
			m_CoinPtr->setPosition(m_GridPtr->getRandomPositionInGrid());
			m_CoinPositioned = true;
		}
	}

	void SnakeGamestate::UpdateDebugText() {
		sf::Vector2f _SnakeHeadPosition = m_SnakePtr->getSnakeHeadPosition();
		m_DebugText.setTextString("SnakeHeadPosition X: " + std::to_string(_SnakeHeadPosition.x) + " ~ Y: " + std::to_string(_SnakeHeadPosition.y));
	}

}