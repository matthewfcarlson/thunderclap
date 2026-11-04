#include "compat/ptr.h"
extern "C" char DAT_00429420[];
typedef unsigned int U_25fba0;
struct MetaTypeAttribBase {
    void* vptr;
    char pad[0x10];
    U_25fba0 a;
    U_25fba0 b;
    MetaTypeAttribBase* init(void*, hulk_uintptr, hulk_uintptr);
};
extern "C" bool __cdecl FUN_0025f450(void *, void *, const char **);
MetaTypeAttribBase* MetaTypeAttribBase::init(void* p, hulk_uintptr c, hulk_uintptr d) {
    a = d;
    vptr = (void*)((hulk_intptr)DAT_00429420);
    b = c;
    d = c;
    FUN_0025f450((char*)p + 0x14, (MetaTypeAttribBase *)this, (const char **)(&d));
    return this;
}