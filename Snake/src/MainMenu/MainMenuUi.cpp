#include "MainMenuUi.hpp"

#include <input/Keyboard.hpp>
#include <input/Mouse.hpp>
#include <graphics/Window.hpp>
#include <Defines.hpp>

#include "../SnakeGameLogic/Game.hpp"

namespace jp
{

	MainMenuUi::MainMenuUi(Game &p_GameRef) :
		m_StartGameBtn(p_GameRef.getWindowRef(), DEFAULT_FONT, "Start"),
		m_OptionsBtn(p_GameRef.getWindowRef(), DEFAULT_FONT, "Options"),
		m_QuitBtn(p_GameRef.getWindowRef(), DEFAULT_FONT, "Quit"),
		m_GameNameText(p_GameRef.getWindowRef(), DEFAULT_FONT),
		m_WindowPtr(&p_GameRef.getWindowRef()),
		m_GamePtr(&p_GameRef) //
	{
	}

	MainMenuUi::~MainMenuUi() {
		m_GamePtr = nullptr;
		m_WindowPtr = nullptr;
	}

	void MainMenuUi::onInit() {
		this->initializeButtons();
	}

	void MainMenuUi::onInput(sf::Event &p_EventRef) {
		if (Keyboard::KeyPressed(KEY_ESCAPE))
		{
			m_WindowPtr->close();
		}
		if (m_StartGameBtn.isMouseHovering() && Mouse::KeyPressed(KEY_LEFT_MOUSE_BTN))
		{
			m_GamePtr->changeGameState(Gamestates::SnakeGame);
		}
		if (m_QuitBtn.isMouseHovering() && Mouse::KeyPressed(KEY_LEFT_MOUSE_BTN))
		{
			m_WindowPtr->close();
		}
	}

	void MainMenuUi::onUpdate(double p_ElapsedTime) {
		m_StartGameBtn.onUpdate(p_ElapsedTime);
		m_OptionsBtn.onUpdate(p_ElapsedTime);
		m_QuitBtn.onUpdate(p_ElapsedTime);
	}

	void MainMenuUi::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		m_StartGameBtn.onDraw(p_RenderWindowRef);
		m_OptionsBtn.onDraw(p_RenderWindowRef);
		m_QuitBtn.onDraw(p_RenderWindowRef);
	}

	void MainMenuUi::onWindowResize() {
		float _scaleX = m_WindowPtr->getWindowInformations().s_WindowScaleFactor.x;
		float _scaleY = m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y;

		m_QuitBtn.setScale(sf::Vector2f(_scaleX, _scaleY));
		m_QuitBtn.setOrigin(sf::Vector2f(m_QuitBtn.getTextButtonSize().x / 2.f, m_QuitBtn.getTextButtonSize().y));
		m_QuitBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_WindowPtr->getWindowResolutionAsFloat().y - (m_PaddingFromWindowBottom * _scaleY)));

		m_OptionsBtn.setScale(sf::Vector2f(_scaleX, _scaleY));
		m_OptionsBtn.setOrigin(sf::Vector2f(m_OptionsBtn.getTextButtonSize().x / 2, m_OptionsBtn.getTextButtonSize().y));
		m_OptionsBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_QuitBtn.getTextButtonPosPoints().top - (m_PaddingBetweenButtons * _scaleY)));

		m_StartGameBtn.setScale(sf::Vector2f(_scaleX, _scaleY));
		m_StartGameBtn.setOrigin(sf::Vector2f(m_StartGameBtn.getTextButtonSize().x / 2, m_StartGameBtn.getTextButtonSize().y));
		m_StartGameBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_OptionsBtn.getTextButtonPosPoints().top - (m_PaddingBetweenButtons * _scaleY)));
	}

	void MainMenuUi::initializeButtons() {
		m_QuitBtn.setTextStyle(sf::Text::Bold);
		m_QuitBtn.setFontSize(m_ButtonFontSize);
		m_QuitBtn.setOrigin(sf::Vector2f(m_QuitBtn.getTextButtonSize().x / 2.f, m_QuitBtn.getTextButtonSize().y));
		m_QuitBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_WindowPtr->getWindowResolutionAsFloat().y - (m_PaddingFromWindowBottom * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y)));
		m_QuitBtn.setOutlineColor(sf::Color(0, 0, 160, 255));
		m_QuitBtn.setTextColor(sf::Color(0, 0, 180, 255));
		m_QuitBtn.setHoverEffectSizeOffset(5);
		m_QuitBtn.setOutlineThickness(1.f);

		m_OptionsBtn.setTextStyle(sf::Text::Bold);
		m_OptionsBtn.setFontSize(m_ButtonFontSize);
		m_OptionsBtn.setOrigin(sf::Vector2f(m_OptionsBtn.getTextButtonSize().x / 2, m_OptionsBtn.getTextButtonSize().y));
		m_OptionsBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_QuitBtn.getTextButtonPosPoints().top - (m_PaddingBetweenButtons * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y)));
		m_OptionsBtn.setOutlineColor(sf::Color(0, 0, 160, 255));
		m_OptionsBtn.setTextColor(sf::Color(0, 0, 180, 255));
		m_OptionsBtn.setHoverEffectSizeOffset(5);
		m_OptionsBtn.setOutlineThickness(1.f);

		m_StartGameBtn.setTextStyle(sf::Text::Bold);
		m_StartGameBtn.setFontSize(m_ButtonFontSize);
		m_StartGameBtn.setOrigin(sf::Vector2f(m_StartGameBtn.getTextButtonSize().x / 2, m_StartGameBtn.getTextButtonSize().y));
		m_StartGameBtn.setPosition(sf::Vector2f(m_WindowPtr->getWindowResolutionAsFloat().x / 2, m_OptionsBtn.getTextButtonPosPoints().top - (m_PaddingBetweenButtons * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y)));
		m_StartGameBtn.setOutlineColor(sf::Color(0, 0, 160, 255));
		m_StartGameBtn.setTextColor(sf::Color(0, 0, 180, 255));
		m_StartGameBtn.setHoverEffectSizeOffset(5);
		m_StartGameBtn.setOutlineThickness(1.f);
	}

}