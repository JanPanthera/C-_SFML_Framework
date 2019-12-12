#include "Framework.hpp"

#include "../input/Keyboard.hpp"
#include "LogToFile.hpp"

#include "../Defines.hpp"

namespace jp
{

	Framework::Framework() {
		LogToFile::Log(LogToFile::LogAttention::DEBUG, "Framework initialization started...", "logs/Framework.log", false);
		Framework::m_EventPtr = new sf::Event();
	}

	Framework::~Framework() {
		Framework::m_WindowPtr = nullptr;
		delete m_EventPtr;
	}

	bool Framework::onRun() {
		if (this->onInit() != _SUCCESS) // pure virtual
		{
			return _FAILED;
		}
		while (m_WindowPtr->isOpen())
		{
			Framework::m_Timestep = m_TimestepClock.restart().asSeconds();
			while (m_WindowPtr->pollEvent(*m_EventPtr))
			{
				switch (m_EventPtr->type)
				{
				case sf::Event::Closed:
					Framework::m_WindowPtr->close();
					break;
				case sf::Event::Resized:
					Framework::m_WindowPtr->onResize();
					this->onWindowResize(); // pure virtual
					break;
				}
				this->onInput(*m_EventPtr); // pure virtual
			}
			this->onUpdate(m_Timestep.AsSeconds()); // pure virtual
			Framework::draw();
		}
		return false;
	}

	void Framework::setWindowPtr(Window &p_WindowRef) {
		m_WindowPtr = &p_WindowRef;
	}

	void Framework::draw() {
		Framework::m_WindowPtr->clear();
		this->onDraw(m_WindowPtr->getRenderWindowRef()); // pure virtual
		Framework::m_WindowPtr->display();
	}

}