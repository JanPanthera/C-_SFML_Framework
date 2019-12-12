#pragma once

#include <string>

namespace jp
{


	class LogToFile
	{
	public:
		enum class LogAttention
		{
			INFO = 0,
			ERROR = 1,
			DEBUG = 2,
			WARNING = 3,
			CRITICAL = 4
		};

	public:
		static void Log(std::string p_TextToLog, std::string p_FileName, bool p_Append = true);
		static void Log(LogAttention p_LogAttention, std::string p_TextToLog, std::string p_FileName, bool p_Append = true);

	public:
		static void setLogAttention(LogAttention p_LogAttention, bool p_Enabled);

	private:
		static bool m_LogAttentionEnabled[5];
		static std::string m_AttentionStrings[5];

	};

}