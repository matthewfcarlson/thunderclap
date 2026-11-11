// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335900 FUN_00335900 (108 B): equivalent/0x00335900.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00335900@Target_335900@fn_f598d243@@QAE_NHHPAD@Z
#include "gen/owners.h"
namespace fn_f598d243 {} using namespace fn_f598d243;
namespace fn_f598d243 {
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 8/8)
// FUN_00335900 @ 0x00335900
struct TypeInfo_335900 { int kind; };
struct Entry_335900 { char pad0[8]; int kind; TypeInfo_335900 *type; };
struct Table_335900 {
    char pad0[0x44];
    int count;
};
int __cdecl FUN_00337f20(int n);
struct Target_335900 {
    char pad0[4];
    Table_335900 *table;
    char **rows;
    bool FUN_00335900(int idx, int index2, char *out);
};
bool Target_335900::FUN_00335900(int idx, int index2, char *out)
{
    if (idx < 0 || idx >= table->count || ((Entry_335900 *)((owners::Thing_337090 *)table)->FUN_00337090(idx))->kind != 9)
        return false;
    char *base = rows[idx] + 4;
    if (((Entry_335900 *)((owners::Thing_337090 *)table)->FUN_00337090(idx))->type->kind != 0)
        return false;
    int off = FUN_00337f20(0) * index2;
    *out = *(char *)(base + off);
    return true;
}
} // namespace fn_f598d243

