#include "Button.hpp"

#include "../input/Mouse.hpp"

namespace jp
{

	Button::Button()
	{
		Button::m_BtnRect.setPosition(m_DefaultButtonPosition);
		Button::m_BtnRect.setSize(m_DefaultButtonSize);
		Button::m_BtnRect.setFillColor(sf::Color::Green);
	}

	Button::~Button() {
	}

	// public functions
	bool Button::isMouseHovering() const {
		return Button::m_MouseHovered;
	}

	void Button::onUpdate(double p_ElapsedTime) {
		if (Mouse::getMousePosition().x > m_BtnRect.getGlobalBounds().left &&
			Mouse::getMousePosition().x < m_BtnRect.getGlobalBounds().left + m_BtnRect.getGlobalBounds().width &&
			Mouse::getMousePosition().y > m_BtnRect.getGlobalBounds().top &&
			Mouse::getMousePosition().y < m_BtnRect.getGlobalBounds().top + m_BtnRect.getGlobalBounds().height)
		{
			Button::m_MouseHovered = true;
		}
		else
		{
			Button::m_MouseHovered = false;
		}
	}

	void Button::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		p_RenderWindowRef.draw(m_BtnRect);
	}

	void Button::move(sf::Vector2f p_MoveAmount) {
		Button::m_BtnRect.move(p_MoveAmount);
		Button::m_DefaultButtonPosition += p_MoveAmount;
	}

	// protected Setter
	void Button::setPosition(sf::Vector2f p_NewPosition) {
		Button::m_DefaultButtonPosition = p_NewPosition;
		Button::m_BtnRect.setPosition(p_NewPosition);
	}

	void Button::setSize(sf::Vector2f p_NewSize) {
		Button::m_DefaultButtonSize = p_NewSize;
		Button::m_BtnRect.setSize(p_NewSize);
	}

	void Button::setScale(sf::Vector2f p_NewScale) {
		Button::m_BtnRect.setScale(p_NewScale);
		Button::m_DefaultButtonPosition = Button::m_BtnRect.getPosition();
		Button::m_DefaultButtonSize = Button::m_BtnRect.getSize();
	}

	void Button::setOrigin(sf::Vector2f p_OriginOffset) {
		Button::m_BtnRect.setOrigin(p_OriginOffset);
	}

	void Button::setFillColor(sf::Color p_NewColor) {
		Button::m_BtnRect.setFillColor(p_NewColor);
	}

}