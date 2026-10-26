#include "gen/global.h"

#include "compat/ptr.h"
typedef unsigned int u32_621a0;
struct Track_621a0 {
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
struct Param_621a0 {
    virtual void p1();
    virtual void p2();
    virtual void p4();
};
extern int query(u32_621a0, int, const void*, const void*, int);
extern void* alloc(hulk_uintptr);
struct CWeaponCollisionAction_621a0 {
    u32_621a0 construct(u32_621a0, CWeaponCollisionTrack*, int);
};
extern const int rtti1;
extern const int rtti2;

hulk_intptr CWeaponCollisionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_621a0 a = (u32_621a0)__p0; u32_621a0 b = (u32_621a0)__p1; u32_621a0 c = (u32_621a0)__p2;

    int x = query(c, 0, &rtti1, &rtti2, 0);
    if (x) {
        void* p = alloc(0x80);
        if (p)
            return (int)(((CWeaponCollisionAction_621a0*)p)->construct(a, this, x));
    }
    return (int)(0);
}
