/* This file is part of Dilay
 * Copyright © 2015-2018 Alexander Bau
 * Use and redistribute under the terms of the GNU General Public License
 */
#ifndef DILAY_HASH
#define DILAY_HASH

#include <functional>
#include <utility>
#include <cstdint>

namespace Hash
{
  // cf. `http://www.boost.org/doc/libs/1_55_0/boost/functional/hash/hash.hpp`
  template <typename T> inline void combine (std::size_t& seed, const T& value)
  {
    seed ^= std::hash<T> () (value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
}

namespace std
{
  template <> struct hash<std::pair<unsigned int, unsigned int>>
  {
    inline size_t operator() (const std::pair<unsigned int, unsigned int>& pair) const
    {
      // Improved hashing for ui_pair mapping that ensures avalanche effect.
      // Boost's combine mixes state, but for integers we can achieve
      // better performance with a direct 64-bit mixer like splitmix64.
      size_t x = pair.first;
      size_t y = pair.second;
      size_t state = x ^ (y * 0xc2b2ae3d27d4eb4fULL);

      state ^= state >> 30;
      state *= 0xbf58476d1ce4e5b9ULL;
      state ^= state >> 27;
      state *= 0x94d049bb133111ebULL;
      state ^= state >> 31;

      return state;
    }
  };

  template <typename T1, typename T2> struct hash<std::pair<T1, T2>>
  {
    inline size_t operator() (const std::pair<T1, T2>& pair) const
    {
      size_t seed = 0;
      Hash::combine (seed, pair.first);
      Hash::combine (seed, pair.second);
      return seed;
    }
  };
}

#endif
