#include "Window.hpp"

#include <Windows.h>

namespace jp
{

	Window::Window() //
	{
		m_RenderWindowPtr = new sf::RenderWindow(sf::VideoMode(m_WindowInformations.s_WindowResolution.x, m_WindowInformations.s_WindowResolution.y),
												 m_WindowInformations.s_WindowTitle, (int)m_WindowInformations.s_WindowStyle);

		m_WindowInformations.s_WindowPosition = sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2) - (m_WindowInformations.s_WindowResolution.x / 2),
			(sf::VideoMode::getDesktopMode().height / 2) - (m_WindowInformations.s_WindowResolution.y / 2));

		sf::FloatRect _visibleArea = sf::FloatRect((float)m_WindowInformations.s_WindowViewPos.x, (float)m_WindowInformations.s_WindowViewPos.y,
			(float)m_WindowInformations.s_WindowViewSize.x, (float)m_WindowInformations.s_WindowViewSize.y);
		m_RenderWindowPtr->setView(sf::View(_visibleArea));

		m_RenderWindowPtr->setPosition(m_WindowInformations.s_WindowPosition);
		m_RenderWindowPtr->setFramerateLimit(m_WindowInformations.s_FramerateLimit);
		m_RenderWindowPtr->setVerticalSyncEnabled(m_WindowInformations.s_VerticalSyncState);
		m_WindowInformations.s_TitleBarSize = this->getTitlebarHeight();
		m_WindowInformations.s_BorderSize = this->getWindowBorderSize();

		m_WindowInformations.s_WindowScaleFactor = sf::Vector2f(m_WindowInformations.s_WindowResolution.x / m_WindowInformations.s_WindowScaleBaseResolution.x,
																m_WindowInformations.s_WindowResolution.y / m_WindowInformations.s_WindowScaleBaseResolution.y);
	}

	Window::Window(Window::WindowInformations p_WindowInformations, bool p_CenterWindow, bool p_SetToDesktopResolution) //
	{
		m_WindowInformations.s_TitleBarSize = this->getTitlebarHeight();
		m_WindowInformations.s_BorderSize = this->getWindowBorderSize();
		m_WindowInformations = p_WindowInformations;
		if (p_SetToDesktopResolution)
		{
			m_WindowInformations.s_WindowPosition = sf::Vector2i(0, 0);
			m_WindowInformations.s_WindowResolution = sf::Vector2i(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
			m_WindowInformations.s_WindowViewPos = sf::Vector2i(0, 0);
			m_WindowInformations.s_WindowViewSize = sf::Vector2i(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
		}
		m_RenderWindowPtr = new sf::RenderWindow(sf::VideoMode(m_WindowInformations.s_WindowResolution.x, m_WindowInformations.s_WindowResolution.y),
												 m_WindowInformations.s_WindowTitle, (int)m_WindowInformations.s_WindowStyle);

		if (p_CenterWindow)
		{
			m_WindowInformations.s_WindowPosition = sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2) - (m_WindowInformations.s_WindowResolution.x / 2),
				(sf::VideoMode::getDesktopMode().height / 2) - (m_WindowInformations.s_WindowResolution.y / 2));
		}

		sf::FloatRect _visibleArea = sf::FloatRect((float)m_WindowInformations.s_WindowViewPos.x, (float)m_WindowInformations.s_WindowViewPos.y,
			(float)m_WindowInformations.s_WindowViewSize.x, (float)m_WindowInformations.s_WindowViewSize.y);
		m_RenderWindowPtr->setView(sf::View(_visibleArea));

		m_RenderWindowPtr->setPosition(m_WindowInformations.s_WindowPosition);
		m_RenderWindowPtr->setFramerateLimit(m_WindowInformations.s_FramerateLimit);
		m_RenderWindowPtr->setVerticalSyncEnabled(m_WindowInformations.s_VerticalSyncState);

		m_WindowInformations.s_WindowScaleFactor = sf::Vector2f(m_WindowInformations.s_WindowResolution.x / m_WindowInformations.s_WindowScaleBaseResolution.x,
																m_WindowInformations.s_WindowResolution.y / m_WindowInformations.s_WindowScaleBaseResolution.y);
	}

	Window::~Window() {
		delete m_RenderWindowPtr;
	}

	void Window::close() {
		m_RenderWindowPtr->close();
	}

	void Window::clear() {
		m_RenderWindowPtr->clear(m_WindowInformations.s_ClearColor);
	}

	void Window::display() {
		m_RenderWindowPtr->display();
	}

	void Window::onResize() {
		sf::FloatRect _visibleArea = sf::FloatRect(0, 0, (float)m_RenderWindowPtr->getSize().x, (float)m_RenderWindowPtr->getSize().y);

		m_WindowInformations.s_LastResizeAmount = sf::Vector2f(-(m_WindowInformations.s_WindowResolution.x - _visibleArea.width),
															   -(m_WindowInformations.s_WindowResolution.y - _visibleArea.height));

		m_WindowInformations.s_WindowViewPos = sf::Vector2i(_visibleArea.left, _visibleArea.top);
		m_WindowInformations.s_WindowViewSize = sf::Vector2i(_visibleArea.width, _visibleArea.height);
		m_WindowInformations.s_WindowPosition = m_RenderWindowPtr->getPosition();
		m_WindowInformations.s_WindowResolution = sf::Vector2i(_visibleArea.width, _visibleArea.height);
		m_WindowInformations.s_WindowScaleFactor = sf::Vector2f(_visibleArea.width / m_WindowInformations.s_WindowScaleBaseResolution.x,
																_visibleArea.height / m_WindowInformations.s_WindowScaleBaseResolution.y);
		m_RenderWindowPtr->setView(sf::View(_visibleArea));
	}

	bool Window::isOpen() const {
		return m_RenderWindowPtr->isOpen();
	}

	bool Window::pollEvent(sf::Event &p_Event) const {
		return m_RenderWindowPtr->pollEvent(p_Event);
	}

	// public Setter
	void Window::setVerticalSyncState(bool p_VerticalSyncState) {
		m_WindowInformations.s_VerticalSyncState = p_VerticalSyncState;
		m_RenderWindowPtr->setVerticalSyncEnabled(p_VerticalSyncState);
	}

	void Window::setFramerateLimit(unsigned int p_FramerateLimit) {
		m_WindowInformations.s_FramerateLimit = p_FramerateLimit;
		m_RenderWindowPtr->setFramerateLimit(p_FramerateLimit);
	}

	void Window::setClearColor(sf::Color p_NewClearColor) {
		m_WindowInformations.s_ClearColor = p_NewClearColor;
	}

	// public Getter
	sf::Vector2f Window::getWindowResolutionAsFloat() const {
		return sf::Vector2f((float)m_WindowInformations.s_WindowResolution.x, (float)m_WindowInformations.s_WindowResolution.y);
	}

	sf::FloatRect Window::getWindowViewAsFloatRect() const {
		return sf::FloatRect((float)m_WindowInformations.s_WindowViewPos.x,
			(float)m_WindowInformations.s_WindowViewPos.y,
							 (float)m_WindowInformations.s_WindowViewSize.x,
							 (float)m_WindowInformations.s_WindowViewSize.y
		);
	}

	sf::RenderWindow &Window::getRenderWindowRef() const {
		return *m_RenderWindowPtr;
	}

	Window::WindowInformations Window::getWindowInformations() const {
		return m_WindowInformations;
	}

	int Window::getTitlebarHeight() {
		return GetSystemMetrics(SM_CXSIZE);
	}

	int Window::getWindowBorderSize() {
		return GetSystemMetrics(SM_CXSIZEFRAME);
	}

}