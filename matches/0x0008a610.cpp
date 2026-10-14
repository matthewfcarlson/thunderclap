struct Vector {
    int x, y, z;
};
class CGameFlowManager {
  public:
    virtual Vector* Get(Vector*);
};
typedef Vector* (CGameFlowManager::*Fn_8a610)(Vector*);
class Method0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CGameFlowManager* mgr, void* unused, Vector* out);
    char pad[0x18];
    Fn_8a610 mFn;
};
void Method0::vfunc_2(CGameFlowManager* mgr, void*, Vector* out) {
    Fn_8a610 fn = mFn;
    Vector temp;
    volatile Vector r;
    Vector* p = (mgr->*fn)(&temp);
    r.x = p->x;
    r.y = p->y;
    r.z = p->z;
    if (out) {
        out->x = r.x;
        out->y = r.y;
        out->z = r.z;
    }
}
