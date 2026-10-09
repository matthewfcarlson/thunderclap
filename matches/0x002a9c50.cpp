typedef unsigned int u32;
struct Obj {
    virtual void f0();
};
struct Ent {
    virtual void a();
    virtual void b();
};
extern int rttiA, rttiB;
extern Obj* cast(void*, int, int*, int*, int);
class pure3d_BillboardQuadGroupAnimationController {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(Obj*);
    char pad[0x40 - 4];
    Ent* member;
};
void pure3d_BillboardQuadGroupAnimationController::vfunc_5(Obj* p) {
    Obj* x = cast(p, 0, &rttiA, &rttiB, 0);
    if (x)
        x->f0();
    if (member)
        member->b();
    member = (Ent*)x;
}