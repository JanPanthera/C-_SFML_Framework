#include "TextBtn.hpp"

#include "../graphics/Window.hpp"

#include "../system/LogToFile.hpp"

namespace jp
{

	TextBtn::TextBtn(Window &p_WindowRef, std::string p_FontFilePath, std::string p_ButtonText) :
		Button(),
		GuiElement() //
	{
		if (!m_Font.loadFromFile(p_FontFilePath))
		{
			LogToFile::Log(LogToFile::LogAttention::ERROR, "Failed to load font. " + p_FontFilePath + " ~ TextBtn.cpp", "logs/Framework.log");
		}
		m_Text.setFont(m_Font);
		m_Text.setString(p_ButtonText);
		Button::setFillColor(sf::Color::Transparent);

		m_Text.setPosition(Button::m_DefaultButtonPosition);
		m_Text.setCharacterSize(m_DefaultFontSize);
		m_TextFixPositioningOrigin = sf::Vector2f(m_Text.getLocalBounds().left, m_Text.getLocalBounds().top);
		m_Text.setOrigin(m_TextFixPositioningOrigin);
		Button::setPosition(sf::Vector2f(m_Text.getGlobalBounds().left, m_Text.getGlobalBounds().top));
		Button::setSize(sf::Vector2f(m_Text.getGlobalBounds().width, m_Text.getGlobalBounds().height));
	}

	TextBtn::~TextBtn() {
	}

	// public functions
	void TextBtn::onUpdate(double p_ElapsedTime) {
		Button::onUpdate(p_ElapsedTime);
		if (Button::isMouseHovering() and m_HoverEffectEnabled)
		{
			if (!m_HoverEffectSetted)
			{
				m_HoverEffectSetted = true;
				m_Text.setCharacterSize(m_DefaultFontSize + m_DefaultHoverEffectSizeOffset);
				m_Text.setOutlineThickness(m_DefaultOutlineThickness + 1);
			}
		}
		else if (!Button::isMouseHovering() and m_HoverEffectEnabled)
		{
			m_HoverEffectSetted = false;
			m_Text.setCharacterSize(m_DefaultFontSize);
			m_Text.setOutlineThickness(m_DefaultOutlineThickness);
		}
	}

	void TextBtn::onDraw(sf::RenderWindow &p_RenderWindowRef) {
		Button::onDraw(p_RenderWindowRef);
		p_RenderWindowRef.draw(m_Text);
	}

	// public Setter
	void TextBtn::setPosition(sf::Vector2f p_NewPosition) {
		m_Text.setPosition(p_NewPosition);
		Button::setPosition(p_NewPosition);
	}

	void TextBtn::setFontSize(unsigned int p_NewFontSize) {
		m_DefaultFontSize = p_NewFontSize;
		m_Text.setCharacterSize(p_NewFontSize);

		m_TextFixPositioningOrigin = sf::Vector2f(m_Text.getLocalBounds().left, m_Text.getLocalBounds().top);
		m_Text.setOrigin(m_Text.getLocalBounds().left, m_Text.getLocalBounds().top);

		Button::setPosition(sf::Vector2f(m_Text.getGlobalBounds().left, m_Text.getGlobalBounds().top));
		Button::setSize(sf::Vector2f(m_Text.getGlobalBounds().width, m_Text.getGlobalBounds().height));
	}

	void TextBtn::setScale(sf::Vector2f p_NewScale) {
		m_Text.setScale(p_NewScale);
		Button::setScale(p_NewScale);
	}

	void TextBtn::setOrigin(sf::Vector2f p_OriginOffset) {
		m_TextOrigin = p_OriginOffset;
		m_Text.setOrigin(m_TextFixPositioningOrigin + p_OriginOffset);
		Button::setOrigin(p_OriginOffset);
	}

	void TextBtn::setTextColor(sf::Color p_NewColor) {
		m_Text.setFillColor(p_NewColor);
	}

	void TextBtn::setOutlineColor(sf::Color p_NewColor) {
		m_Text.setOutlineColor(p_NewColor);
	}

	void TextBtn::setFillColorColor(sf::Color p_NewColor) {
		Button::setFillColor(p_NewColor);
	}

	void TextBtn::setTextStyle(sf::Uint32 p_NewStyle) {
		m_Text.setStyle(p_NewStyle);
	}

	void TextBtn::setButtonText(std::string p_NewString) {
		m_Text.setString(p_NewString);
		Button::setPosition(sf::Vector2f(m_Text.getGlobalBounds().left, m_Text.getGlobalBounds().top));
		Button::setSize(sf::Vector2f(m_Text.getGlobalBounds().width, m_Text.getGlobalBounds().height));
	}

	void TextBtn::setOutlineThickness(float p_NewOutlineThickness) {
		m_DefaultOutlineThickness = p_NewOutlineThickness;
		m_Text.setOutlineThickness(p_NewOutlineThickness);
	}

	void TextBtn::setHoverEffectEnabled(bool p_EnabledHoverEffect) {
		m_HoverEffectEnabled = p_EnabledHoverEffect;
	}

	void TextBtn::setHoverEffectSizeOffset(unsigned int p_HoverEffectsSizeOffset) {
		m_DefaultHoverEffectSizeOffset = p_HoverEffectsSizeOffset;
	}

	// public Getter
	sf::Vector2f TextBtn::getTextButtonSize() const {
		return sf::Vector2f(m_Text.getLocalBounds().width, m_Text.getLocalBounds().height);
	}

	sf::Vector2f TextBtn::getTextButtonPosition() const {
		return m_Text.getPosition();
	}

	sf::FloatRect TextBtn::getTextButtonPosPoints() const {
		return m_Text.getGlobalBounds();
	}

}