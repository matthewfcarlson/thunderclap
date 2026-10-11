extern "C" void _ReadWriteBarrier();
struct Child {
    virtual void a();
    virtual void b();
};
struct CGameControllerManager {
    void* vptr;
    Child* child;
    CGameControllerManager* vfunc_0(unsigned char p);
};
void thunk_FUN_00267090(CGameControllerManager*);
CGameControllerManager* CGameControllerManager::vfunc_0(unsigned char p) {
    vptr = (void*)0x405e3c;
    _ReadWriteBarrier();
    child->b();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}
