// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x003356d0 FUN_003356d0 (81 B): equivalent/0x003356d0.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_003356d0@Object@fn_f43e7bad@@QAE_NHPAH00@Z @f8fcebd790e2 @we518001cdeab
#include "gen/owners.h"
namespace fn_f43e7bad {} using namespace fn_f43e7bad;
namespace fn_f43e7bad {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_003356d0 @ 0x003356d0
struct Entry { char pad[8]; int type; }; struct Info { char pad[0x44]; int count;  }; struct Triple { int x,y,z; }; struct Object { char pad[4]; Info* info; Triple** values; bool FUN_003356d0(int index, int* x, int* y, int* z); }; bool Object::FUN_003356d0(int index, int* x, int* y, int* z) { if (index < 0 || index >= info->count) return false; if (((Entry *)((owners::Thing_337090 *)info)->FUN_00337090(index))->type != 6) return false; Triple* p = values[index]; *x = p->x; *y = p->y; *z = p->z; return true; }
} // namespace fn_f43e7bad

