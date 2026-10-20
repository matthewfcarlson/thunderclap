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
extern Lock gLock_2765d0;
extern Mgr_2765d0* gMgr_2765d0;
extern int vt0_2765d0, vt4, vtR;
void __cdecl Enter(Lock*);
void __cdecl Leave(Lock*);
struct Sub_2765d0 {
    void Dtor();
};
struct File {
    int v0, v4, v8;
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
        Enter(&gLock_2765d0);
        gMgr_2765d0->Free(this);
        Leave(&gLock_2765d0);
    }
    return this;
}
