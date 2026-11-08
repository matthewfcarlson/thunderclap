#include "decls/data/engine/core.h"
#include "decls/data/records.h"
// data: gLock_2765d0 = DAT_0052a1e8
#include "compat/ptr.h"
struct Mgr_2765d0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void Free(void* p);
};
struct Obj_2765d0 {
    virtual void o0();
    virtual void Rel();
};
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042bd30[];
extern "C" char DAT_0042bd3c[];
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
struct Sub_2765d0 {
    void FUN_00277c30();
};
// core::File's deleting destructor (records.h CoreFile): waits for its requests (vfunc_21 0x00276240), releases the
// drive and the library view (0x00277c30); the memory goes back to the "File" pool (0x0052a204, its lock 0x0052a1e8)
struct File_2765d0 : CoreFile {
    File_2765d0* Fn(unsigned char f);
    void FUN_00276240();
};
File_2765d0* File_2765d0::Fn(unsigned char f) {
    vftable = DAT_0042bd3c;
    vftableMutable = DAT_0042bd30;
    FUN_00276240();
    ((Obj_2765d0*)provider)->Rel();
    ((Sub_2765d0*)&view)->FUN_00277c30();
    vftable = DAT_003f6098;
    if (f & 1) {
        FUN_0026d850(((char*)&DAT_0052a1e8));
        (*(Mgr_2765d0**)&DAT_0052a204)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1e8));
    }
    return this;
}
