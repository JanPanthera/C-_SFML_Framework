#include "Time.hpp"

#include <iostream>
#include <time.h>

namespace jp
{

	Time::DateTime Time::m_CurrentDateTime = {};

	std::string Time::getCurrentTimeString() {
		Time::setCurrentDateAndTime();
		return "[" + Time::m_CurrentDateTime.s_Hours + ":" + Time::m_CurrentDateTime.s_Minutes + ":" + Time::m_CurrentDateTime.s_Seconds + "]";
	}

	std::string Time::getCurrentDateString() {
		Time::setCurrentDateAndTime();
		return "[" + Time::m_CurrentDateTime.s_Day + "-" + Time::m_CurrentDateTime.s_Month + "-" + Time::m_CurrentDateTime.s_Year + "]";
	}

	void Time::setCurrentDateAndTime() {
		time_t current_time;
		struct tm  local_time;

		time(&current_time);
		localtime_s(&local_time, &current_time);

		Time::m_CurrentDateTime.s_Seconds = local_time.tm_sec < 10 ? "0" + std::to_string(local_time.tm_sec) : std::to_string(local_time.tm_sec);
		Time::m_CurrentDateTime.s_Minutes = local_time.tm_min < 10 ? "0" + std::to_string(local_time.tm_min) : std::to_string(local_time.tm_min);
		Time::m_CurrentDateTime.s_Hours = local_time.tm_hour < 10 ? "0" + std::to_string(local_time.tm_hour) : std::to_string(local_time.tm_hour);
		Time::m_CurrentDateTime.s_Day = local_time.tm_mday < 10 ? "0" + std::to_string(local_time.tm_mday) : std::to_string(local_time.tm_mday);
		Time::m_CurrentDateTime.s_Month = local_time.tm_mon < 10 ? "0" + std::to_string(local_time.tm_mon + 1) : std::to_string(local_time.tm_mon + 1);
		Time::m_CurrentDateTime.s_Year = std::to_string(local_time.tm_year + 1900);
	}

}