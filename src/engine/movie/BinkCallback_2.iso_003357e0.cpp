// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x003357e0 FUN_003357e0 (87 B): equivalent/0x003357e0.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_003357e0@Owner@fn_f1bb6fd6@@QAE_NHPAH@Z @dfd476743088 @w4ce679eff0f2
#include "gen/owners.h"
namespace fn_f1bb6fd6 {} using namespace fn_f1bb6fd6;
namespace fn_f1bb6fd6 {
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 10/10)
// FUN_003357e0 @ 0x003357e0
struct Entry { char pad[8]; int type; };
struct Container { char pad[0x44]; int count;  };
struct Owner { char pad[4]; Container* container; char** strings; bool FUN_003357e0(int index, int* length); };
bool Owner::FUN_003357e0(int index, int* length) {
    if (index < 0 || index >= container->count || ((Entry *)((owners::Thing_337090 *)container)->FUN_00337090(index))->type != 10)
        return false;
    const char* text = strings[index];
    if (!text) { *length = 0; return true; }
    int n = 0;
    while (text[n]) ++n;
    *length = n;
    return true;
}
} // namespace fn_f1bb6fd6

