#pragma once

#include <string>

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

namespace jp
{
	class Window
	{
	public:
		enum class WinStyle
		{
			None = 0,
			Titlebar = 1,
			Resize = 2,
			Close = 4,
			Default = 7,
			Fullscreen = 8
		};

		struct WindowInformations
		{
			bool s_VerticalSyncState{true};
			int s_BorderSize{0};
			int s_TitleBarSize{0};
			unsigned int s_FramerateLimit{0};
			WinStyle s_WindowStyle{WinStyle::Default};
			sf::Color s_ClearColor{sf::Color::Black};
			sf::Vector2i s_WindowViewPos{0, 0};
			sf::Vector2i s_WindowViewSize{1920, 1080};
			sf::Vector2i s_WindowPosition{0, 0};
			sf::Vector2i s_WindowResolution{1920, 1080};
			sf::Vector2f s_WindowScaleFactor{1.f, 1.f};
			sf::Vector2f s_WindowScaleBaseResolution{1920.f, 1080.f};
			sf::Vector2f s_LastResizeAmount{0.f, 0.f};
			std::string s_WindowTitle{"Window title not set"};
		};

	public:
		Window();
		Window(WindowInformations p_WindowInformations, bool p_CenterWindow = true, bool p_SetToDesktopResolution = false);
		~Window();

	public:
		void close();
		void clear();
		void display();

	public:
		bool isOpen() const;
		bool pollEvent(sf::Event &p_Event) const;
		void onResize();

	public:
		void setVerticalSyncState(bool p_VerticalSyncState);
		void setFramerateLimit(unsigned int p_FramerateLimit);
		void setClearColor(sf::Color p_Color);

	public:
		sf::Vector2f getWindowResolutionAsFloat() const;
		sf::FloatRect getWindowViewAsFloatRect() const;
		sf::RenderWindow &getRenderWindowRef() const;
		WindowInformations getWindowInformations() const;

	private:
		int getTitlebarHeight();
		int getWindowBorderSize();

	private:
		WindowInformations m_WindowInformations{};
		sf::RenderWindow *m_RenderWindowPtr{nullptr};

	};

}