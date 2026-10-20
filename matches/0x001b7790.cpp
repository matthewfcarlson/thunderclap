#include "compat/ptr.h"
class RenderThing_1b7790 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int rad_vtable;
extern int ref_vtable;
class CRadMovieRenderLoop {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CRadMovieRenderLoop* vfunc_2(unsigned char);
    virtual void vfunc_3();
    char pad[8];
    RenderThing_1b7790* member;
};
extern void destroy(CRadMovieRenderLoop*);
CRadMovieRenderLoop* CRadMovieRenderLoop::vfunc_2(unsigned char flags) {
    *(hulk_intptr*)this = (hulk_intptr)&rad_vtable;
    member->f1();
    *(hulk_intptr*)this = (hulk_intptr)&ref_vtable;
    if (flags & 1)
        destroy(this);
    return this;
}