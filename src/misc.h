/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008-2014 Marco Costalba, Joona Kiiski, Tord Romstad

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MISC_H_INCLUDED
#define MISC_H_INCLUDED

#include <ostream>
#include <string>
#include <vector>

#include "types.h"

const std::string engine_info(bool to_uci = false);
void timed_wait(WaitCondition&, Lock&, int);
void prefetch(char* addr);
void start_logger(bool b);

void dbg_hit_on(bool b);
void dbg_hit_on_c(bool c, bool b);
void dbg_mean_of(int v);
void dbg_print();


namespace Time {
  typedef int64_t point;
  inline point now() { return system_time_to_msec(); }
}


template<class Entry, int Size>
struct HashTable {
  HashTable() : table(Size, Entry()) {}
  Entry* operator[](Key k) { return &table[(uint32_t)k & (Size - 1)]; }

private:
  std::vector<Entry> table;
};


enum SyncCout { IO_LOCK, IO_UNLOCK };
std::ostream& operator<<(std::ostream&, SyncCout);

#define sync_cout std::cout << IO_LOCK
#define sync_endl std::endl << IO_UNLOCK

#endif // #ifndef MISC_H_INCLUDED
