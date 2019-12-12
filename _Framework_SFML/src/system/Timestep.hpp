#pragma once

namespace jp
{
	class Timestep
	{
	public:
		Timestep(double p_Time = 0.0);

	public:
		double AsSeconds() const;
		double AsMilliseconds() const;

	private:
		double m_Time{0.0};

	};

}