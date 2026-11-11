// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00335e60 FUN_00335e60 (143 B): equivalent/0x00335e60.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00335e60@Reader@fn_f1c3e55f@@QAE_NHHPAI@Z
#include "gen/owners.h"
namespace fn_f1c3e55f {} using namespace fn_f1c3e55f;
namespace fn_f1c3e55f {
// STATUS: equivalent (tools/equiv.py level 3: 3031 inputs, branch coverage 12/12)
// FUN_00335e60 @ 0x00335e60
struct TypeInfo_335e60 {
    int kind;
};

struct Value_335e60 {
    char pad00[8];
    int type;                // 0x08
    TypeInfo_335e60 *info;          // 0x0c
};

class Table_335e60 {
public:
    char pad00[0x44];
    int count;               // 0x44
};

int __cdecl FUN_00337f20(int kind);

class Reader {
public:
    char pad00[4];
    Table_335e60 *table;            // 0x04
    char **rows;             // 0x08
    bool FUN_00335e60(int column, int row, unsigned int *outLength);
};

// Length of the string stored in a string-typed column (0 when null).
bool Reader::FUN_00335e60(int column, int row, unsigned int *outLength) {
    if (column < 0 || column >= table->count)
        return false;
    if (((Value_335e60 *)((owners::Thing_337090 *)table)->FUN_00337090(column))->type != 9)
        return false;
    char *base = rows[column] + 4;
    if (((Value_335e60 *)((owners::Thing_337090 *)table)->FUN_00337090(column))->info->kind != 10)
        return false;
    const char *s = *(const char **)(base + FUN_00337f20(10) * row);
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
} // namespace fn_f1c3e55f

