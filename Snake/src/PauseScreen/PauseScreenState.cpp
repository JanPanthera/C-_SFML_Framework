#include "PauseScreenState.hpp"

#include <system/LogToFile.hpp>
#include <input/Keyboard.hpp>
#include <input/Mouse.hpp>
#include <Defines.hpp>

#include "../SnakeGameLogic/Game.hpp"

namespace jp
{

	PauseScreenState::PauseScreenState(Game &p_GameRef) :
		m_PauseScreenUi(p_GameRef),
		m_GamePtr(&p_GameRef),
		m_WindowPtr(&p_GameRef.getWindowRef()) //
	{
	}

	PauseScreenState::~PauseScreenState() {
		m_GamePtr = nullptr;
		m_WindowPtr = nullptr;
	}

	void PauseScreenState::onInit() {
		m_PauseScreenUi.onInit();
	}

	void PauseScreenState::onInput(sf::Event &p_EventRef) {
		m_PauseScreenUi.onInput(p_EventRef);
	}

	void PauseScreenState::onUpdate(double p_ElapsedTime) {
		m_PauseScreenUi.onUpdate(p_ElapsedTime);
	}

	void PauseScreenState::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		m_PauseScreenUi.onDraw(p_RenderWindowRef);
	}

	void PauseScreenState::onWindowResize() {
		m_PauseScreenUi.onWindowResize();
	}

}