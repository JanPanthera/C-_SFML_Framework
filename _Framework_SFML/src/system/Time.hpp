#pragma once

#include <string>

namespace jp
{

	class Time
	{
	public:
		struct DateTime
		{
			std::string s_Seconds = "";
			std::string s_Minutes = "";
			std::string s_Hours = "";
			std::string s_Day = "";
			std::string s_Month = "";
			std::string s_Year = "";
		};

	public:
		static std::string getCurrentTimeString();
		static std::string getCurrentDateString();

	private:
		static void setCurrentDateAndTime();

	private:
		static Time::DateTime m_CurrentDateTime;

	};

}