#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace jp
{

	class Button
	{
	public:
		Button();
		~Button();

	public:
		bool isMouseHovering() const;

	protected:
		void onUpdate(double p_ElapsedTime);
		void onDraw(sf::RenderWindow &p_RenderWindowRef);

	protected:
		void move(sf::Vector2f p_MoveAmount);
		void setPosition(sf::Vector2f p_NewPosition);
		void setSize(sf::Vector2f p_NewSize);
		void setScale(sf::Vector2f p_NewScale);
		void setOrigin(sf::Vector2f p_OriginOffset);
		void setFillColor(sf::Color p_NewColor);

	protected:
		sf::Vector2f m_DefaultButtonSize{100.f, 50.f};
		sf::Vector2f m_DefaultButtonPosition{0.f, 0.f};

	private:
		sf::RectangleShape m_BtnRect;

	private:
		bool m_MouseHovered{false};


	};

}