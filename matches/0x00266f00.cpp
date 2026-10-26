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
int __cdecl target(int a, int b) {
    return ((S_266f00*)((char*)&DAT_00527c58 + 8))[a].p->f4(b);
}