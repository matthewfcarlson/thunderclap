// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335970 FUN_00335970 (108 B): equivalent/0x00335970.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00335970@Target_335970@fn_f07928c6@@QAE_NHHPAH@Z
#include "gen/owners.h"
namespace fn_f07928c6 {} using namespace fn_f07928c6;
namespace fn_f07928c6 {
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 8/8)
// FUN_00335970 @ 0x00335970
struct TypeInfo_335970 { int kind; };
struct Entry_335970 { char pad0[8]; int kind; TypeInfo_335970 *type; };
struct Table_335970 {
    char pad0[0x44];
    int count;
};
int __cdecl FUN_00337f20(int n);
struct Target_335970 {
    char pad0[4];
    Table_335970 *table;
    char **rows;
    bool FUN_00335970(int idx, int index2, int *out);
};
bool Target_335970::FUN_00335970(int idx, int index2, int *out)
{
    if (idx < 0 || idx >= table->count || ((Entry_335970 *)((owners::Thing_337090 *)table)->FUN_00337090(idx))->kind != 9)
        return false;
    char *base = rows[idx] + 4;
    if (((Entry_335970 *)((owners::Thing_337090 *)table)->FUN_00337090(idx))->type->kind != 1)
        return false;
    int off = FUN_00337f20(1) * index2;
    *out = *(int *)(base + off);
    return true;
}
} // namespace fn_f07928c6

