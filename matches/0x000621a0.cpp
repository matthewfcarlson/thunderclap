#include "compat/ptr.h"
typedef unsigned int u32_621a0;
struct Track {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
};
struct Param {
    virtual void p1();
    virtual void p2();
    virtual void p4();
};
struct CWeaponCollisionTrack : Track, Param {
    virtual void v0();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual u32_621a0 v10(u32_621a0 a, u32_621a0 b, u32_621a0 c);
    virtual void v11();
};
extern int query(u32_621a0, int, const void*, const void*, int);
extern void* alloc(hulk_uintptr);
struct CWeaponCollisionAction_621a0 {
    u32_621a0 construct(u32_621a0, CWeaponCollisionTrack*, int);
};
extern const int rtti1;
extern const int rtti2;
u32_621a0 CWeaponCollisionTrack::v10(u32_621a0 a, u32_621a0 b, u32_621a0 c) {
    int x = query(c, 0, &rtti1, &rtti2, 0);
    if (x) {
        void* p = alloc(0x80);
        if (p)
            return ((CWeaponCollisionAction_621a0*)p)->construct(a, this, x);
    }
    return 0;
}