#pragma once

#include "Button.hpp"
#include "GuiElement.hpp"

#include <SFML/Graphics/Text.hpp>

namespace jp
{

	class Window;
	class TextBtn : public Button, public GuiElement
	{
	public:
		TextBtn(Window &p_WindowRef, std::string p_FontFilePath, std::string p_ButtonText);
		~TextBtn();

	public:
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);

	public:
		void setPosition(sf::Vector2f p_NewPosition);
		void setFontSize(unsigned int p_NewFontSize);
		void setScale(sf::Vector2f p_NewScale);
		void setOrigin(sf::Vector2f p_OriginOffset);
		void setTextColor(sf::Color p_NewColor);
		void setOutlineColor(sf::Color p_NewColor);
		void setFillColorColor(sf::Color p_NewColor);
		void setTextStyle(sf::Uint32 p_NewStyle);
		void setButtonText(std::string p_NewString);
		void setOutlineThickness(float p_NewOutlineThickness);
		void setHoverEffectEnabled(bool p_EnabledHoverEffect);
		void setHoverEffectSizeOffset(unsigned int p_HoverEffectsSizeOffset);

	public:
		sf::Vector2f getTextButtonSize() const;
		sf::Vector2f getTextButtonPosition() const;
		sf::FloatRect getTextButtonPosPoints() const;

	private:
		sf::Vector2f m_TextOrigin{0.0f, 0.0f};
		sf::Vector2f m_TextFixPositioningOrigin{0.0f, 0.0f};

	private:
		sf::Text m_Text;
		sf::Font m_Font;

	private:
		bool m_HoverEffectSetted{false};
		bool m_HoverEffectEnabled{true};
		float m_DefaultOutlineThickness{3.f};
		unsigned int m_DefaultHoverEffectSizeOffset{3};
		unsigned int m_DefaultFontSize{96};

	};
}