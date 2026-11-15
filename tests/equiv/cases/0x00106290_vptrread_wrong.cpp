// STATUS: must fail (tools/equiv.py level 3)
// (integ1, D43 vptrread) deliberately wrong: the second key is not compared.
struct Entry { char pad[8]; int first; int second; };
struct Search { char pad[8]; int count; Entry **entries; int FUN_00106290(int first, int second); };

int Search::FUN_00106290(int first, int second) { for (int i = 0; i < count; ++i) { Entry *entry = entries[i]; if (entry->first == first) return i; } return -1; }
