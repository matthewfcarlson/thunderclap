// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x003358a0 FUN_003358a0 (81 B): equivalent/0x003358a0.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_003358a0@Target@fn_f8e85419@@QAE_NHPAH@Z
#include "gen/owners.h"
namespace fn_f8e85419 {} using namespace fn_f8e85419;
namespace fn_f8e85419 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 8/8)
// FUN_003358a0 @ 0x003358a0
struct Entry { char pad[8]; int kind; }; struct Container { char pad[0x44]; int count;  }; struct Target { char pad[4]; Container* container; int** values; bool FUN_003358a0(int index, int* output); }; bool Target::FUN_003358a0(int index, int* output) { if (index < 0 || index >= container->count || ((Entry *)((owners::Thing_337090 *)container)->FUN_00337090(index))->kind != 9) return false; int* item = values[index]; *output = item ? *item : 0; return true; }
} // namespace fn_f8e85419

