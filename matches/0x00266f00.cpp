#include "decls/data/records.h"

struct C_266f00 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(void*);
};
extern "C" int __cdecl FUN_00266f00(int a, void* b) {
    return ((C_266f00*)DAT_00527c60[a].allocator)->f4(b);
}
