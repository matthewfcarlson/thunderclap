// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335a50 FUN_00335a50 (108 B): equivalent/0x00335a50.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00335a50@Target_335a50@fn_f7546720@@QAE_NHHPAH@Z @0b74afa42313 @we5783bf3edbe
#include "gen/owners.h"
namespace fn_f7546720 {} using namespace fn_f7546720;
namespace fn_f7546720 {
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 8/8)
// FUN_00335a50 @ 0x00335a50
struct TypeInfo_335a50 { int kind; };
struct Entry_335a50 { char pad0[8]; int kind; TypeInfo_335a50 *type; };
struct Table_335a50 {
    char pad0[0x44];
    int count;
};
int __cdecl FUN_00337f20(int n);
struct Target_335a50 {
    char pad0[4];
    Table_335a50 *table;
    char **rows;
    bool FUN_00335a50(int idx, int index2, int *out);
};
bool Target_335a50::FUN_00335a50(int idx, int index2, int *out)
{
    if (idx < 0 || idx >= table->count || ((Entry_335a50 *)((owners::Thing_337090 *)table)->FUN_00337090(idx))->kind != 9)
        return false;
    char *base = rows[idx] + 4;
    if (((Entry_335a50 *)((owners::Thing_337090 *)table)->FUN_00337090(idx))->type->kind != 3)
        return false;
    int off = FUN_00337f20(3) * index2;
    *out = *(int *)(base + off);
    return true;
}
} // namespace fn_f7546720

