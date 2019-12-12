#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../math/Vector2f.hpp"

namespace jp
{

	class GuiElement
	{
	public:
		GuiElement();
		~GuiElement();

	public:
		void setGuiElementSize(Vector2f p_NewSize);
		void setGuiElementPosition(Vector2f p_NewPosition);

	public:
		Vector2f getGuiElementSize() const;
		Vector2f getGuiElementPosition() const;

	private:
		Vector2f m_SizeVec2;
		Vector2f m_PositionVec2;

	private:
		sf::RectangleShape m_GuiElementShape;
		sf::Texture m_GuiTexture;

	};

}