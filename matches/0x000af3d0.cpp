extern "C" char DAT_00405e3c[];
extern "C" void _ReadWriteBarrier();
struct Child_af3d0 {
    virtual void a();
    virtual void b();
};
struct CGameControllerManager {
    void* vptr;
    Child_af3d0* child;
    CGameControllerManager* vfunc_0(unsigned char p);
};
void thunk_FUN_00267090(CGameControllerManager*);
CGameControllerManager* CGameControllerManager::vfunc_0(unsigned char p) {
    vptr = (void*)((int)DAT_00405e3c);
    _ReadWriteBarrier();
    child->b();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}
