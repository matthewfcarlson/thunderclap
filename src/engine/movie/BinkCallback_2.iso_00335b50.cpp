// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335b50 FUN_00335b50 (123 B): equivalent/0x00335b50.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00335b50@Table_335b50@fn_f50248db@@QAE_NHHPAD@Z @0641f661f7db @w56bfbe7f2edf
#include "gen/owners.h"
namespace fn_f50248db {} using namespace fn_f50248db;
namespace fn_f50248db {
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 12/12)
// FUN_00335b50 @ 0x00335b50
struct Column {
    char pad0[8];
    int type;
    int *kind;
};

struct Schema_335b50 {

    char pad0[0x44];
    int count;
};

int __cdecl FUN_00337f20(int kind);

class Table_335b50 {
public:
    bool FUN_00335b50(int index, int column, char *out);

    char pad0[4];
    Schema_335b50 *schema;
    char **rows;
};

// Copies the string stored in a string-typed cell of a row into `out`.
bool Table_335b50::FUN_00335b50(int index, int column, char *out) {
    if (index < 0 || index >= schema->count) {
        return false;
    }
    if (((Column *)((owners::Thing_337090 *)schema)->FUN_00337090(index))->type != 9) {
        return false;
    }
    char *row = rows[index] + 4;
    if (*((Column *)((owners::Thing_337090 *)schema)->FUN_00337090(index))->kind != 4) {
        return false;
    }
    char *src = *(char **)(row + FUN_00337f20(4) * column);
    if (src == 0) {
        return false;
    }
    char c;
    do {
        c = *src++;
        *out++ = c;
    } while (c);
    return true;
}
} // namespace fn_f50248db

