#include "LooseScreen.hpp"

#include <system/LogToFile.hpp>
#include <input/Keyboard.hpp>
#include <input/Mouse.hpp>
#include <Defines.hpp>

#include "../SnakeGameLogic/Game.hpp"

namespace jp
{

	LooseScreenState::LooseScreenState(Game &p_GameRef) :
		m_LooseScreenUi(p_GameRef),
		m_WindowPtr(&p_GameRef.getWindowRef()),
		m_GamePtr(&p_GameRef) //
	{
	}

	LooseScreenState::~LooseScreenState() {
		m_GamePtr = nullptr;
		m_WindowPtr = nullptr;
	}

	void LooseScreenState::onInit() {
		m_LooseScreenUi.onInit();
	}

	void LooseScreenState::onInput(sf::Event &p_EventRef) {
		m_LooseScreenUi.onInput(p_EventRef);
	}

	void LooseScreenState::onUpdate(double p_ElapsedTime) {
		m_LooseScreenUi.onUpdate(p_ElapsedTime);
	}

	void LooseScreenState::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		m_LooseScreenUi.onDraw(p_RenderWindowRef);
	}

	void LooseScreenState::onWindowResize() {
		m_LooseScreenUi.onWindowResize();
	}

}