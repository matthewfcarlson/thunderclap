// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x003355e0 FUN_003355e0 (84 B): equivalent/0x003355e0.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_003355e0@Owner@fn_fb185358@@QAE_NHPAD@Z
#include "gen/owners.h"
namespace fn_fb185358 {} using namespace fn_fb185358;
namespace fn_fb185358 {
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 10/10)
// FUN_003355e0 @ 0x003355e0
struct Entry { char pad[8]; int type; };
struct Collection { char pad[0x44]; int count;  };
struct Owner { char pad[4]; Collection* collection; char** strings; bool FUN_003355e0(int index, char* destination); };
bool Owner::FUN_003355e0(int index, char* destination) {
    if (index < 0 || index >= collection->count || ((Entry *)((owners::Thing_337090 *)collection)->FUN_00337090(index))->type != 4)
        return false;
    const char* source = strings[index];
    if (source) {
        while ((*destination++ = *source++) != 0) {}
    } else {
        *destination = 0;
    }
    return true;
}
} // namespace fn_fb185358

