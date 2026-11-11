// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335840 FUN_00335840 (84 B): equivalent/0x00335840.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00335840@Object@fn_f9da17d4@@QAE_NHPAD@Z
#include "gen/owners.h"
namespace fn_f9da17d4 {} using namespace fn_f9da17d4;
namespace fn_f9da17d4 {
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 10/10)
// FUN_00335840 @ 0x00335840
struct Entry { char pad[8]; int kind; }; struct Database { char pad[0x44]; int count;  }; struct Object { char pad0[4]; Database* database; const char** names; bool FUN_00335840(int index, char* output); }; bool Object::FUN_00335840(int index, char* output) { if (index < 0 || index >= database->count || ((Entry *)((owners::Thing_337090 *)database)->FUN_00337090(index))->kind != 10) return false; const char* name = names[index]; if (name) { do { *output++ = *name; } while (*name++); } else *output = 0; return true; }
} // namespace fn_f9da17d4

