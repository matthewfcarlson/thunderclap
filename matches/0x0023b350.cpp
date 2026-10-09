// Same code shape as 0x001b7790 (propagated; names are from that function)
class RenderThing {
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
    RenderThing* member;
};
extern void destroy(CRadMovieRenderLoop*);
CRadMovieRenderLoop* CRadMovieRenderLoop::vfunc_2(unsigned char flags) {
    *(int*)this = (int)&rad_vtable;
    member->f1();
    *(int*)this = (int)&ref_vtable;
    if (flags & 1)
        destroy(this);
    return this;
}