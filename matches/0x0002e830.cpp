#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" char DAT_003f407c[];
extern "C" char DAT_003f439c[];
typedef unsigned int u32_2e830;
typedef unsigned char u8;
struct ThisCall_001d0480 {
    void InitHelper(const char*, int);
};
u8 GetHelper(const void*);
struct Obj_2e830 {
    u32_2e830 vptr;
    char p4[12];
    u8 b10;
    char p11[7];
    u8 b18;
    char p19[3];
    void* m1c;
    void* m20;
    Obj_2e830* Build(const char*, void*, void*);
};
Obj_2e830* Obj_2e830::Build(const char* a, void* b, void* c) {
    ((ThisCall_001d0480*)(this))->InitHelper(a, 1);
    vptr = ((hulk_intptr)DAT_003f407c);
    m1c = c;
    b18 = GetHelper((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b10 = GetHelper((const void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    vptr = ((hulk_intptr)DAT_003f439c);
    m20 = b;
    return this;
}
