#include "LogToFile.hpp"

#include <fstream>
#include <ctime>

#include "Time.hpp"

namespace jp
{
	bool LogToFile::m_LogAttentionEnabled[] = {false,false,false,false,false};
	std::string LogToFile::m_AttentionStrings[] = {"INFO","ERROR","DEBUG","WARNING","CRITICAL"};

	void LogToFile::Log(std::string p_TextToLog, std::string p_FileName, bool p_Append) {
		std::ofstream _Output(p_FileName, p_Append ? std::ofstream::out | std::ofstream::app : std::ofstream::out);
		std::string _tempString = Time::getCurrentTimeString() + " ~ " + p_TextToLog + "\n";
		_Output.write(_tempString.data(), _tempString.size());
		_Output.close();
	}

	void LogToFile::Log(LogAttention p_LogAttention, std::string p_TextToLog, std::string p_FileName, bool p_Append) {
		if (m_LogAttentionEnabled[(unsigned int)p_LogAttention] == true)
		{
			std::ofstream _Output(p_FileName, p_Append ? std::ofstream::out | std::ofstream::app : std::ofstream::out);
			std::string _tempString = Time::getCurrentTimeString() + " -- [" + m_AttentionStrings[(unsigned int)p_LogAttention] + "] ~ " + p_TextToLog + "\n";
			_Output.write(_tempString.data(), _tempString.size());
			_Output.close();
		}
	}

	void LogToFile::setLogAttention(LogAttention p_LogAttention, bool p_Enabled) {
		if ((unsigned int)p_LogAttention < 5)
		{
			m_LogAttentionEnabled[(unsigned int)p_LogAttention] = p_Enabled;
		}
	}

}