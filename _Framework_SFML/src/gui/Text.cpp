#include "Text.hpp"

#include "../graphics/Window.hpp"

#include "../system/LogToFile.hpp"

namespace jp
{

	Text::Text(Window &p_WindowRef, std::string p_FontFilePath) :
		m_WindowPtr(&p_WindowRef) //
	{
		if (!m_Font.loadFromFile(p_FontFilePath))
		{
			LogToFile::Log(LogToFile::LogAttention::ERROR, "Failed to load font. " + p_FontFilePath + " ~ Text.cpp", "logs/Framework.log");
		}
		Text::m_Text.setFont(m_Font);
	}

	Text::~Text() {
		Text::m_WindowPtr = nullptr;
	}

	// public functions
	void Text::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		p_RenderWindowRef.draw(m_Text);
	}

	void Text::onWindowResize() {
		Text::m_Text.setPosition(sf::Vector2f(Text::m_DefaultTextPosition.x * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.x,
											  Text::m_DefaultTextPosition.y * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y));
		Text::m_DefaultFontSize = m_DefaultFontSize * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.x * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y;
		Text::m_Text.setCharacterSize(m_DefaultFontSize);
		Text::m_DefaultTextPosition = sf::Vector2f(m_Text.getGlobalBounds().left, m_Text.getGlobalBounds().top);
		Text::m_DefaultTextSize = sf::Vector2f(Text::m_Text.getGlobalBounds().width, Text::m_Text.getGlobalBounds().height);
	}

	// public Setter
	void Text::setPosition(sf::Vector2f p_NewPosition) {
		Text::m_Text.setPosition(sf::Vector2f(p_NewPosition.x * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.x,
											  p_NewPosition.y * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y));
		Text::m_DefaultTextPosition = sf::Vector2f(m_Text.getGlobalBounds().left, m_Text.getGlobalBounds().top);
	}

	void Text::setFontSize(unsigned int p_NewFontSize) {
		Text::m_DefaultFontSize = p_NewFontSize * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.x * m_WindowPtr->getWindowInformations().s_WindowScaleFactor.y;
		Text::m_Text.setCharacterSize(m_DefaultFontSize);
		Text::m_DefaultTextPosition = sf::Vector2f(m_Text.getGlobalBounds().left, m_Text.getGlobalBounds().top);
		Text::m_DefaultTextSize = sf::Vector2f(Text::m_Text.getGlobalBounds().width, Text::m_Text.getGlobalBounds().height);
	}

	void Text::setOrigin(sf::Vector2f p_OriginOffset) {
		Text::m_Text.setOrigin(p_OriginOffset);
	}

	void Text::setTextColor(sf::Color p_NewColor) {
		Text::m_Text.setFillColor(p_NewColor);
	}

	void Text::setOutlineColor(sf::Color p_NewColor) {
		Text::m_Text.setOutlineColor(p_NewColor);
	}

	void Text::setTextStyle(sf::Uint32 p_NewStyle) {
		Text::m_Text.setStyle(p_NewStyle);
	}

	void Text::setTextString(std::string p_NewString) {
		Text::m_Text.setString(p_NewString);
		Text::m_DefaultTextPosition = sf::Vector2f(m_Text.getGlobalBounds().left, m_Text.getGlobalBounds().top);
		Text::m_DefaultTextSize = sf::Vector2f(m_Text.getGlobalBounds().width, m_Text.getGlobalBounds().height);
	}

	void Text::setOutlineThickness(float p_NewOutlineThickness) {
		Text::m_Text.setOutlineThickness(p_NewOutlineThickness);
	}

	// public Getter
	sf::Vector2f Text::getTextSize() const {
		return Text::m_DefaultTextSize;
	}

}