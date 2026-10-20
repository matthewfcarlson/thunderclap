// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00304f50 @ 0x00304f50
#include "compat/ptr.h"
extern char DAT_00431b08[];

struct Name_304f50 {
    char data[8];
    void FUN_0027af00();
};

struct CollisionObject {
    int vptr;
    char pad04[0xc];
    Name_304f50 name;
    int f18, f1c, f20, f24, f28, f2c, f30;
    char b34, b35;
    char pad36[2];
    int f38, f3c, f40, f44, f48;
    char b4c, b4d;
    char pad4e[2];
    char b50, b51;
    char pad52[2];
    int f54, f58, f5c, f60, f64;
    char b68, b69, b6a, b6b;
    int f6c;
    char b70, b71, b72;
    char pad73;
    int f74;
    int f78;
    void FUN_0027b070();
    void FUN_00304b40(int arg);
    CollisionObject *FUN_00304f50(int arg);
};

CollisionObject *CollisionObject::FUN_00304f50(int arg)
{
    FUN_0027b070();
    vptr = (hulk_intptr)DAT_00431b08;
    name.FUN_0027af00();
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    b34 = 0;
    b35 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    b4c = 0;
    b4d = 0;
    b50 = 0;
    b51 = 1;
    f54 = 0;
    f58 = 0;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    b6b = 0;
    b71 = 0;
    b68 = 1;
    b69 = 1;
    b6a = 1;
    b70 = 1;
    b72 = 1;
    f78 = 1;
    f6c = 0xf;
    FUN_00304b40(arg);
    f74 = -1;
    return this;
}
