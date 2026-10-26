#include "decls/data/engine/core.h"
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
struct Lock;
extern int vt0_2765d0, vt4, vtR;
void __cdecl Enter(Lock*);
void __cdecl Leave(Lock*);
struct Sub_2765d0 {
    void Dtor();
};
struct File {
    hulk_intptr v0, v4, v8;
    Obj_2765d0* o;
    char pad[0x12c - 0x10];
    Sub_2765d0 sub;
    File* Fn(unsigned char f);
    void Close();
};
File* File::Fn(unsigned char f) {
    *(hulk_intptr*)this = (hulk_intptr)&vt0_2765d0;
    v4 = (hulk_intptr)&vt4;
    Close();
    o->Rel();
    sub.Dtor();
    *(hulk_intptr*)this = (hulk_intptr)&vtR;
    if (f & 1) {
        Enter(((Lock*)&DAT_0052a1e8));
        (*(Mgr_2765d0**)&DAT_0052a204)->Free(this);
        Leave(((Lock*)&DAT_0052a1e8));
    }
    return this;
}
