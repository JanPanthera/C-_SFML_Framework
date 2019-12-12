#include "Timestep.hpp"

namespace jp
{

	Timestep::Timestep(double p_Time) :
		m_Time(p_Time)
	{
	}

	double Timestep::AsSeconds() const {
		return m_Time;
	}

	double Timestep::AsMilliseconds() const {
		return m_Time * 1000.0;
	}

}