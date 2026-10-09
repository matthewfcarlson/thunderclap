class LocomotionStrafe4Track {
  public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_3();
    virtual int vfunc_4();
    virtual int vfunc_5();
    virtual int vfunc_6();
    virtual int vfunc_7();
    virtual int vfunc_8();
    virtual int vfunc_9();
    virtual int vfunc_10(int, int, int);
};
class Helper {
  public:
    int run(LocomotionStrafe4Track*, int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
int LocomotionStrafe4Track::vfunc_10(int a, int b, int c) {
    void* p = FUN_0008d690(0x48);
    if (p)
        return ((Helper*)p)->run(this, c);
    return 0;
}