// Same code shape as 0x002830e0 (propagated; names are from that function)
class Obj_2a8650 {
  public:
    virtual void f();
    virtual void g();
};
class CMotionTrail {
  public:
    char pad[0x40];
    Obj_2a8650* mObj;
    void vfunc_8(Obj_2a8650* p);
};
void CMotionTrail::vfunc_8(Obj_2a8650* p) {
    if (p)
        p->f();
    if (mObj)
        mObj->g();
    mObj = p;
}