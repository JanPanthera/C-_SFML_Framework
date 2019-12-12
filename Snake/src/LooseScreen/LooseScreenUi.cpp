#include "LooseScreenUi.hpp"

#include <input/Keyboard.hpp>
#include <input/Mouse.hpp>
#include <graphics/Window.hpp>
#include <Defines.hpp>

#include "../SnakeGameLogic/Game.hpp"

namespace jp
{

	LooseScreenUi::LooseScreenUi(Game &p_GameRef) :
		m_RestartBtn(p_GameRef.getWindowRef(), DEFAULT_FONT, "Restart"),
		m_QuitBtn(p_GameRef.getWindowRef(), DEFAULT_FONT, "Quit"),
		m_LooseText(p_GameRef.getWindowRef(), DEFAULT_FONT),
		m_WindowPtr(&p_GameRef.getWindowRef()),
		m_GamePtr(&p_GameRef) //
	{
	}

	LooseScreenUi::~LooseScreenUi() {
		m_GamePtr = nullptr;
		m_WindowPtr = nullptr;
	}

	void LooseScreenUi::onInit() {
		this->initializeButtons();
	}

	void LooseScreenUi::onInput(sf::Event &p_EventRef) {
		if (m_RestartBtn.isMouseHovering() and Mouse::KeyPressed(KEY_LEFT_MOUSE_BTN))
		{
			m_GamePtr->restart();
		}
		if (m_QuitBtn.isMouseHovering() and Mouse::KeyPressed(KEY_LEFT_MOUSE_BTN))
		{
			m_WindowPtr->close();
		}
	}

	void LooseScreenUi::onUpdate(double p_ElapsedTime) {
		m_RestartBtn.onUpdate(p_ElapsedTime);
		m_QuitBtn.onUpdate(p_ElapsedTime);
	}

	void LooseScreenUi::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		m_RestartBtn.onDraw(p_RenderWindowRef);
		m_QuitBtn.onDraw(p_RenderWindowRef);
	}

	void LooseScreenUi::onWindowResize() {
		float _scaleX = m_WindowPtr->getWindowInformations().s_WindowScaleFactor.x;
		float _scaleY = m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y;

		m_QuitBtn.setScale(sf::Vector2f(_scaleX, _scaleY));
		m_QuitBtn.setOrigin(sf::Vector2f(m_QuitBtn.getTextButtonSize().x / 2.f, m_QuitBtn.getTextButtonSize().y));
		m_QuitBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_WindowPtr->getWindowResolutionAsFloat().y - (m_PaddingFromWindowBottom * _scaleY)));

		m_RestartBtn.setScale(sf::Vector2f(_scaleX, _scaleY));
		m_RestartBtn.setOrigin(sf::Vector2f(m_RestartBtn.getTextButtonSize().x / 2, m_RestartBtn.getTextButtonSize().y));
		m_RestartBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_QuitBtn.getTextButtonPosPoints().top - (m_PaddingBetweenButtons * _scaleY)));
	}

	void LooseScreenUi::initializeButtons() {
		m_QuitBtn.setTextStyle(sf::Text::Bold);
		m_QuitBtn.setFontSize(m_ButtonFontSize);
		m_QuitBtn.setOrigin(sf::Vector2f(m_QuitBtn.getTextButtonSize().x / 2.f, m_QuitBtn.getTextButtonSize().y));
		m_QuitBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_WindowPtr->getWindowResolutionAsFloat().y - (m_PaddingFromWindowBottom * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y)));
		m_QuitBtn.setOutlineColor(sf::Color(0, 0, 160, 255));
		m_QuitBtn.setTextColor(sf::Color(0, 0, 180, 255));
		m_QuitBtn.setHoverEffectSizeOffset(5);
		m_QuitBtn.setOutlineThickness(1.f);

		m_RestartBtn.setTextStyle(sf::Text::Bold);
		m_RestartBtn.setFontSize(m_ButtonFontSize);
		m_RestartBtn.setOrigin(sf::Vector2f(m_RestartBtn.getTextButtonSize().x / 2, m_RestartBtn.getTextButtonSize().y));
		m_RestartBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_QuitBtn.getTextButtonPosPoints().top - (m_PaddingBetweenButtons * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y)));
		m_RestartBtn.setOutlineColor(sf::Color(0, 0, 160, 255));
		m_RestartBtn.setTextColor(sf::Color(0, 0, 180, 255));
		m_RestartBtn.setHoverEffectSizeOffset(5);
		m_RestartBtn.setOutlineThickness(1.f);
	}

}