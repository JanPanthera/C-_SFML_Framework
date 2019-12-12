#pragma once

namespace sf
{
	class Event;
	class RenderWindow;
}

namespace jp
{

	class Gamestate
	{
	public:
		Gamestate() {};
		virtual ~Gamestate() {};
		virtual void onInput(sf::Event &p_EventRef) = 0;
		virtual void onUpdate(double p_ElapsedTime) = 0;
		virtual void onDraw(sf::RenderWindow &p_RenderWindowRef) = 0;

	};

}