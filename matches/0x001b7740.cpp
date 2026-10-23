#include "compat/ptr.h"
#include "gen/pure3d.h"
typedef unsigned int u32_1b7740;
extern "C" int __cdecl alloc(hulk_intptr);
extern int movieVtable;
struct Inner_1b7740 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(u32_1b7740, u32_1b7740);
};
struct Made_1b7740 {
    char pad[0x10];
    Inner_1b7740* p;
};
struct Shader_nv_1b7740 {
    Made_1b7740* make();
};
struct CRadMovieRenderLoop_1b7740 {
    hulk_uintptr vptr;
    int state;
    int zero;
    Made_1b7740* made;
};
CRadMovieRenderLoop_1b7740* __fastcall FUN_001b7740(CRadMovieRenderLoop_1b7740* self) {
    self->vptr = (hulk_uintptr)&movieVtable;
    self->state = -2;
    self->zero = 0;
    hulk_intptr t = alloc(32);
    Made_1b7740* m;
    if (t)
        m = ((Shader_nv_1b7740*)(((pure3d::Shader*)(((pure3d::Shader*)t)))))->make();
    else
        m = 0;
    self->made = m;
    m->p->g(0x444d4c42, 1);
    return self;
}