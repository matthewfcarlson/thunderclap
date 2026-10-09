class Obj {
  public:
    virtual void f();
    virtual void g();
};
class CMotionTrail {
  public:
    char pad[0x40];
    Obj* mObj;
    void vfunc_8(Obj* p);
};
void CMotionTrail::vfunc_8(Obj* p) {
    if (p)
        p->f();
    if (mObj)
        mObj->g();
    mObj = p;
}