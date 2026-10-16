// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 18/18)
// FUN_001d04d0 @ 0x001d04d0
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

struct TypeInfo_1d04d0 {
    int FUN_00344913(const TypeInfo_1d04d0 *other) const;
};

extern TypeInfo_1d04d0 DAT_0048e10c;

char FUN_001d04d0(const TypeInfo_1d04d0 *t)
{
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e100)))
        return 'v';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e0e4)))
        return 'b';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0049cad8)) || t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e0f0)))
        return 's';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e134)) || t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0049b95c)))
        return 'i';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e128)))
        return 'f';
    if (t->FUN_00344913(&DAT_0048e10c))
        return 'V';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_004c5cbc)))
        return 1;
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_004c5ca0)))
        return 1;
    return 'c';
}
