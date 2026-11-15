// STATUS: equivalent (tools/equiv.py level 3)
// (integ1, D43 vptrread) a loop over a pointer array with no call at all: vptrkeep's tracker read each loaded word
// with a mapping read, so the original's run mapped pages past the 1000-page limit and returned where ours stopped at
// too_many_pages (directed input 7). The tracker's reads map nothing now.
struct Entry { char pad[8]; int first; int second; };
struct Search { char pad[8]; int count; Entry **entries; int FUN_00106290(int first, int second); };

int Search::FUN_00106290(int first, int second) { for (int i = 0; i < count; ++i) { Entry *entry = entries[i]; if (entry->first == first && entry->second == second) return i; } return -1; }
