#pragma once

#include <random>

namespace jp
{

	class Random
	{
	public:
		template<class _Type>
		static _Type getRandomBetween(_Type p_RangeMin, _Type p_RangeMax) {
			std::random_device _RandomDevice;
			std::mt19937 _rng(_RandomDevice());
			std::uniform_int_distribution<std::mt19937::result_type> dist(p_RangeMin, p_RangeMax);
			return (_Type)dist(_rng);
		}
	};

}