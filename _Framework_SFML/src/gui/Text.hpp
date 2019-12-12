#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace jp
{

	class Window;
	class Text
	{
	public:
		Text(Window &p_WindowRef, std::string p_FontFilePath);
		~Text();

	public:
		void onDraw(sf::RenderWindow &p_RenderWindowRef);
		void onWindowResize();

	public:
		void setPosition(sf::Vector2f p_NewPosition);
		void setFontSize(unsigned int p_NewFontSize);
		void setOrigin(sf::Vector2f p_OriginOffset);
		void setTextColor(sf::Color p_NewColor);
		void setOutlineColor(sf::Color p_NewColor);
		void setTextStyle(sf::Uint32 p_NewStyle);
		void setTextString(std::string p_NewString);
		void setOutlineThickness(float p_NewOutlineThickness);

	public:
		sf::Vector2f getTextSize() const;

	private:
		unsigned int m_DefaultFontSize{96};
		sf::Vector2f m_DefaultTextSize{10.f, 10.f};
		sf::Vector2f m_DefaultTextPosition{0.f, 0.f};

	private:
		sf::Font m_Font;
		sf::Text m_Text;

	private:
		Window *m_WindowPtr{nullptr};

	};

}