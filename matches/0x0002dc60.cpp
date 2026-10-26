#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern int VTable_2dc60;
struct Function_2dc60 {
    Function_2dc60(const char*, int);
};
struct Method3_2dc60 : Function_2dc60 {
    char pad0[16];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int field1c;
    Method3_2dc60(const char*, int);
};
Method3_2dc60::Method3_2dc60(const char* a, int x) : Function_2dc60(a, 3) {
    *(hulk_intptr*)this = (hulk_intptr)&VTable_2dc60;
    field1c = x;
    b18 = FUN_001d04d0(((const char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b11 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b12 = FUN_001d04d0(((const char*)&DAT_0048e128));
}