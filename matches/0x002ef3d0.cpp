class Obj_2ef3d0 {
  public:
    virtual void Run();
    virtual void Release();
};
class SimState {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void vfunc_13(void*);
    char pad[0x70 - 4];
    Obj_2ef3d0* mObj;
};
void SimState::vfunc_13(void* p) {
    if (mObj)
        mObj->Release();
    mObj = (Obj_2ef3d0*)p;
    mObj->Run();
}
