// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 18/18)
// FUN_001d04d0 @ 0x001d04d0
struct TypeInfo {
    int FUN_00344913(const TypeInfo *other) const;
};

extern TypeInfo DAT_0048e100;
extern TypeInfo DAT_0048e0e4;
extern TypeInfo DAT_0049cad8;
extern TypeInfo DAT_0048e0f0;
extern TypeInfo DAT_0048e134;
extern TypeInfo DAT_0049b95c;
extern TypeInfo DAT_0048e128;
extern TypeInfo DAT_0048e10c;
extern TypeInfo DAT_004c5cbc;
extern TypeInfo DAT_004c5ca0;

char FUN_001d04d0(const TypeInfo *t)
{
    if (t->FUN_00344913(&DAT_0048e100))
        return 'v';
    if (t->FUN_00344913(&DAT_0048e0e4))
        return 'b';
    if (t->FUN_00344913(&DAT_0049cad8) || t->FUN_00344913(&DAT_0048e0f0))
        return 's';
    if (t->FUN_00344913(&DAT_0048e134) || t->FUN_00344913(&DAT_0049b95c))
        return 'i';
    if (t->FUN_00344913(&DAT_0048e128))
        return 'f';
    if (t->FUN_00344913(&DAT_0048e10c))
        return 'V';
    if (t->FUN_00344913(&DAT_004c5cbc))
        return 1;
    if (t->FUN_00344913(&DAT_004c5ca0))
        return 1;
    return 'c';
}
