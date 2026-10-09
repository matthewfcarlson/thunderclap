struct Vector { int x,y,z; };
class CGameFlowManager { public: virtual Vector* Get(Vector*); };
typedef Vector* (CGameFlowManager::*Fn)(Vector*);
class Method0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CGameFlowManager* mgr, void* unused, Vector* out);
    char pad[0x18];
    Fn mFn;
};
void Method0::vfunc_2(CGameFlowManager* mgr, void*, Vector* out) {
    Fn fn = mFn;
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
