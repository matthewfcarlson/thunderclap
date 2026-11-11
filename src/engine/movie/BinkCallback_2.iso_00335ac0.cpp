// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00335ac0 FUN_00335ac0 (143 B): equivalent/0x00335ac0.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00335ac0@Reader@fn_f5ad0173@@QAE_NHHPAI@Z
#include "gen/owners.h"
namespace fn_f5ad0173 {} using namespace fn_f5ad0173;
namespace fn_f5ad0173 {
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 12/12)
// FUN_00335ac0 @ 0x00335ac0
struct TypeInfo_335ac0 {
    int kind;
};

struct Value_335ac0 {
    char pad00[8];
    int type;                // 0x08
    TypeInfo_335ac0 *info;          // 0x0c
};

class Table_335ac0 {
public:
    char pad00[0x44];
    int count;               // 0x44
};

int __cdecl FUN_00337f20(int kind);

class Reader {
public:
    char pad00[4];
    Table_335ac0 *table;            // 0x04
    char **rows;             // 0x08
    bool FUN_00335ac0(int column, int row, unsigned int *outLength);
};

// Length of the string stored in a string-typed column (0 when null).
bool Reader::FUN_00335ac0(int column, int row, unsigned int *outLength) {
    if (column < 0 || column >= table->count)
        return false;
    if (((Value_335ac0 *)((owners::Thing_337090 *)table)->FUN_00337090(column))->type != 9)
        return false;
    char *base = rows[column] + 4;
    if (((Value_335ac0 *)((owners::Thing_337090 *)table)->FUN_00337090(column))->info->kind != 4)
        return false;
    const char *s = *(const char **)(base + FUN_00337f20(4) * row);
    if (s == 0) {
        *outLength = 0;
        return true;
    }
    const char *e = s;
    while (*e)
        e++;
    *(hulk_uintptr*)outLength = e - s;
    return true;
}
} // namespace fn_f5ad0173

