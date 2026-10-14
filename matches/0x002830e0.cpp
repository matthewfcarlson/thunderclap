class Obj_2830e0 {
  public:
    virtual void f();
    virtual void g();
};
class CMotionTrail {
  public:
    char pad[0x40];
    Obj_2830e0* mObj;
    void vfunc_8(Obj_2830e0* p);
};
void CMotionTrail::vfunc_8(Obj_2830e0* p) {
    if (p)
        p->f();
    if (mObj)
        mObj->g();
    mObj = p;
}