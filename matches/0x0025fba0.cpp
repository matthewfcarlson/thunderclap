#include "compat/ptr.h"
extern "C" char DAT_00429420[];
typedef unsigned int U_25fba0;
struct MetaTypeAttribBase {
    void* vptr;
    char pad[0x10];
    U_25fba0 a;
    U_25fba0 b;
    MetaTypeAttribBase* init(void*, U_25fba0, U_25fba0);
};
void __cdecl FUN_0025f450(void*, MetaTypeAttribBase*, U_25fba0*);
MetaTypeAttribBase* MetaTypeAttribBase::init(void* p, U_25fba0 c, U_25fba0 d) {
    a = d;
    vptr = (void*)((hulk_intptr)DAT_00429420);
    b = c;
    d = c;
    FUN_0025f450((char*)p + 0x14, this, &d);
    return this;
}