typedef unsigned int u32_2a9c50;
struct Obj_2a9c50 {
    virtual void f0();
};
struct Ent_2a9c50 {
    virtual void a();
    virtual void b();
};
extern int rttiA_2a9c50, rttiB;
extern Obj_2a9c50* cast(void*, int, int*, int*, int);
class pure3d_BillboardQuadGroupAnimationController {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(Obj_2a9c50*);
    char pad[0x40 - 4];
    Ent_2a9c50* member;
};
void pure3d_BillboardQuadGroupAnimationController::vfunc_5(Obj_2a9c50* p) {
    Obj_2a9c50* x = cast(p, 0, &rttiA_2a9c50, &rttiB, 0);
    if (x)
        x->f0();
    if (member)
        member->b();
    member = (Ent_2a9c50*)x;
}