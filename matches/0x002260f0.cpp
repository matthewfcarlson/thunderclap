class LocomotionStrafeDriver {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void vfunc_14(float);
    char pad[0x2c];
    unsigned int count;
    char rest[0x208];
};
extern float __cdecl FUN_0022aaa0(float, float);
void LocomotionStrafeDriver::vfunc_14(float param) {
    unsigned int i = 0;
    if (count > 0) {
        char* p = (char*)this + 0x238;
        do {
            *(float*)p = FUN_0022aaa0(param, *(float*)(p - 0x204));
            ++i;
            p += 0x208;
        } while (i < count);
    }
}