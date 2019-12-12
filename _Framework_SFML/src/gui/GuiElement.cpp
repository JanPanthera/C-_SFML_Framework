#include "GuiElement.hpp"

namespace jp
{

	GuiElement::GuiElement() {
	}

	GuiElement::~GuiElement() {
	}

	void GuiElement::setGuiElementSize(Vector2f p_NewSize) {
		GuiElement::m_SizeVec2.set_Vec2(p_NewSize);
	}

	void GuiElement::setGuiElementPosition(Vector2f p_NewPosition) {
		GuiElement::m_PositionVec2 = p_NewPosition;
	}

	Vector2f GuiElement::getGuiElementSize() const {
		return GuiElement::m_SizeVec2.get_Vec2();
	}

	Vector2f GuiElement::getGuiElementPosition() const {
		return GuiElement::m_PositionVec2;
	}

}