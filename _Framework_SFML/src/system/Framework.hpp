#pragma once

#include "..\graphics\Window.hpp"
#include "Timestep.hpp"

namespace jp
{

	class Framework
	{
	public:
		Framework();
		~Framework();

	public:
		bool onRun();

	public:
		virtual bool onInit() = 0;
		virtual void onInput(sf::Event &p_EventRef) = 0;
		virtual void onUpdate(double p_ElapsedTime) = 0;
		virtual void onDraw(sf::RenderWindow &p_RenderWindowRef) = 0;
		virtual void onWindowResize() = 0;

	public:
		void setWindowPtr(Window &p_WindowRef);

	private:
		void draw();

	private:
		Timestep m_Timestep{};
		jp::Window *m_WindowPtr{nullptr};

		sf::Clock m_TimestepClock{};
		sf::Event *m_EventPtr{nullptr};

	};

}