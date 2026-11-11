// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335cc0 FUN_00335cc0 (129 B): equivalent/0x00335cc0.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00335cc0@Reader@fn_f6597df8@@QAE_NHHPAH00@Z
#include "gen/owners.h"
namespace fn_f6597df8 {} using namespace fn_f6597df8;
namespace fn_f6597df8 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8)
// FUN_00335cc0 @ 0x00335cc0
// 0x00335cc0: read three words of element `stride`-th record from a type-9 entry with a type-6 layout
struct Layout_335cc0 {
    int kind;
};

struct Info_335cc0 {
    char pad00[8];
    int type;
    Layout_335cc0* layout;
};

struct Table_335cc0 {
    char pad00[0x44];
    int count;
};

int __cdecl FUN_00337f20(int kind);

class Reader {
public:
    char pad00[4];
    Table_335cc0* table;
    int* records;
    bool FUN_00335cc0(int index, int stride, int* out0, int* out1, int* out2);
};

bool Reader::FUN_00335cc0(int index, int stride, int* out0, int* out1, int* out2)
{
    if (index < 0 || index >= table->count)
        return false;
    if (((Info_335cc0 *)((owners::Thing_337090 *)table)->FUN_00337090(index))->type != 9)
        return false;

    int* base = (int*)(records[index] + 4);
    if (((Info_335cc0 *)((owners::Thing_337090 *)table)->FUN_00337090(index))->layout->kind != 6)
        return false;

    int* rec = (int*)((char*)base + FUN_00337f20(6) * stride);
    *out0 = rec[0];
    *out1 = rec[1];
    *out2 = rec[2];
    return true;
}
} // namespace fn_f6597df8

