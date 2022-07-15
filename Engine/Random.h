#pragma once
#include <random>

namespace Engine
{
	inline void SeedRandom(int seed) { srand(seed); }

	inline int RandomInt() { return rand(); }
	inline int RandomInt(int max) { return RandomInt() % max; } // exclusive, does not include max in return
	inline int RandomInt(int min, int max) { return min + RandomInt() % (max - min) + 1; } // inclusive of min and max
}
