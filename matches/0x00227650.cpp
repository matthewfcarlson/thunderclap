extern "C" char DAT_004273c4[];
typedef unsigned int u32_227650;
void* __cdecl alloc_obj(unsigned int);
class LocomotionStrafeDriver {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
class Helper_227650 {
  public:
    void a(LocomotionStrafeDriver*);
    void b(LocomotionStrafeDriver*);
};
void* LocomotionStrafeDriver::vfunc_5() {
    void* p = alloc_obj(0x1330);
    if (p) {
        ((Helper_227650*)p)->a(this);
        *(u32_227650*)p = ((int)DAT_004273c4);
        ((Helper_227650*)p)->b(this);
        return p;
    }
    return 0;
}