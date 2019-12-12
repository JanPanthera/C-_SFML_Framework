#include "Game.hpp"

#include <input/Keyboard.hpp>

namespace jp
{
	Game::Game() {
	}

	Game::~Game() {
		delete m_PauseScreenStatePtr;
		delete m_SnakeGamestatePtr;
		delete m_MainMenustatePtr;
		delete m_LooseScreenPtr;
		delete m_WindowPtr;
	}

	bool Game::onInit() {
		LogToFile::setLogAttention(LOG_INFO, true);
		LogToFile::setLogAttention(LOG_ERROR, true);
		LogToFile::setLogAttention(LOG_DEBUG, true);
		LogToFile::setLogAttention(LOG_WARNING, true);
		LogToFile::setLogAttention(LOG_CRITICAL, true);
		LogToFile::Log(LOG_INFO, "Game log started...", "logs/Snake.log", false);

		if (this->initWindow() != _SUCCESS or this->initGamestates() != _SUCCESS)
		{
			return _FAILED;
		}

		m_MainMenustatePtr->onInit();
		m_PauseScreenStatePtr->onInit();
		m_LooseScreenPtr->onInit();

		return _SUCCESS;
	}

	void Game::onInput(sf::Event &p_EventRef) {
		switch (m_GameStates)
		{
		case Gamestates::MainMenu:
			m_MainMenustatePtr->onInput(p_EventRef);
			break;
		case Gamestates::SnakeGame:
			m_SnakeGamestatePtr->onInput(p_EventRef);
			break;
		case Gamestates::PauseScreen:
			m_PauseScreenStatePtr->onInput(p_EventRef);
			break;
		case Gamestates::LooseScreen:
			m_LooseScreenPtr->onInput(p_EventRef);
			break;
		}
	}

	void Game::onUpdate(double p_ElapsedTime) {
		switch (m_GameStates)
		{
		case Gamestates::MainMenu:
			m_MainMenustatePtr->onUpdate(p_ElapsedTime);
			break;
		case Gamestates::SnakeGame:
			m_SnakeGamestatePtr->onUpdate(p_ElapsedTime);
			break;
		case Gamestates::PauseScreen:
			m_PauseScreenStatePtr->onUpdate(p_ElapsedTime);
			break;
		case Gamestates::LooseScreen:
			m_LooseScreenPtr->onUpdate(p_ElapsedTime);
			break;
		}
	}

	void Game::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		switch (m_GameStates)
		{
		case Gamestates::MainMenu:
			m_MainMenustatePtr->onDraw(p_RenderWindowRef);
			break;
		case Gamestates::SnakeGame:
			m_SnakeGamestatePtr->onDraw(p_RenderWindowRef);
			break;
		case Gamestates::PauseScreen:
			m_SnakeGamestatePtr->onDraw(p_RenderWindowRef);
			m_PauseScreenStatePtr->onDraw(p_RenderWindowRef);
			break;
		case Gamestates::LooseScreen:
			m_SnakeGamestatePtr->onDraw(p_RenderWindowRef);
			m_LooseScreenPtr->onDraw(p_RenderWindowRef);
		}
	}

	void Game::onWindowResize() {
		m_MainMenustatePtr->onWindowResize();
		m_SnakeGamestatePtr->onWindowResize();
		m_PauseScreenStatePtr->onWindowResize();
		m_LooseScreenPtr->onWindowResize();
	}

	void Game::restart() {
		delete m_SnakeGamestatePtr;
		m_SnakeGamestatePtr = new SnakeGamestate(*this);
		this->changeGameState(Gamestates::SnakeGame);
	}

	void Game::changeGameState(Gamestates p_GameState) {
		m_GameStates = p_GameState;
	}

	Window &Game::getWindowRef() const {
		return *m_WindowPtr;
	}

	bool Game::initWindow() {
		m_Fullscreen = false;
		if (m_Fullscreen)
		{
			Window::WindowInformations _WindowInformations{};
			_WindowInformations.s_WindowStyle = jp::Window::WinStyle::Fullscreen;
			m_WindowPtr = new Window(_WindowInformations, true, true);
		}
		else
		{
			Window::WindowInformations _WindowInformations{};
			_WindowInformations.s_WindowResolution = sf::Vector2i(1366, 768);
			_WindowInformations.s_WindowViewSize = sf::Vector2i(1366, 768);
			_WindowInformations.s_WindowStyle = jp::Window::WinStyle::Default;
			_WindowInformations.s_WindowTitle = "My own Window";
			m_WindowPtr = new Window(_WindowInformations, true, false);
		}
		_IS_NULLPTR(m_WindowPtr);
		Framework::setWindowPtr(*m_WindowPtr);
		return _SUCCESS;
	}

	bool Game::initGamestates() {
		m_LooseScreenPtr = new LooseScreenState(*this);
		_IS_NULLPTR(m_LooseScreenPtr);
		m_MainMenustatePtr = new MainMenustate(*this);
		_IS_NULLPTR(m_MainMenustatePtr);
		m_SnakeGamestatePtr = new SnakeGamestate(*this);
		_IS_NULLPTR(m_SnakeGamestatePtr);
		m_PauseScreenStatePtr = new PauseScreenState(*this);
		_IS_NULLPTR(m_PauseScreenStatePtr);
		m_GameStates = Gamestates::MainMenu;
		return _SUCCESS;
	}

}