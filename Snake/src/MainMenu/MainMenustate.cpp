#include "MainMenustate.hpp"

#include <system/LogToFile.hpp>
#include <input/Keyboard.hpp>
#include <input/Mouse.hpp>
#include <Defines.hpp>

#include "../SnakeGameLogic/Game.hpp"

namespace jp
{
	MainMenustate::MainMenustate(Game &p_GameRef) :
		m_MainMenuUi(p_GameRef),
		m_GamePtr(&p_GameRef),
		m_WindowPtr(&p_GameRef.getWindowRef()) //
	{
	}

	MainMenustate::~MainMenustate() {
		m_GamePtr = nullptr;
		m_WindowPtr = nullptr;
	}

	void MainMenustate::onInit() {
		m_MainMenuUi.onInit();
	}

	void MainMenustate::onInput(sf::Event &p_EventRef) {
		m_MainMenuUi.onInput(p_EventRef);
	}

	void MainMenustate::onUpdate(double p_ElapsedTime) {
		m_MainMenuUi.onUpdate(p_ElapsedTime);
	}

	void MainMenustate::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		m_MainMenuUi.onDraw(p_RenderWindowRef);
	}

	void MainMenustate::onWindowResize() {
		m_MainMenuUi.onWindowResize();
	}

}