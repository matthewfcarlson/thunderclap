#include "compat/ptr.h"
#include "decls/data/engine/content.h"

struct C_266f00 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int);
};
struct S_266f00 {
    C_266f00* p;
    char pad[12];
};
extern "C" int __cdecl FUN_00266f00(int a, hulk_intptr b) {
    return ((S_266f00*)((char*)&DAT_00527c58 + 8))[a].p->f4(b);
}