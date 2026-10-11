extern "C" char DAT_00428db0[];
typedef unsigned int uint;
extern "C" void* __cdecl operator_new(unsigned int);
class TrackFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
class Inner {
  public:
    void init();
};
class StopTrack {
  public:
    virtual void dummy();
    char pad4[4];
    int flag;
    int zero;
    float value;
    Inner inner;
    void init();
};
void* TrackFactoryTemplate::vfunc_5() {
    StopTrack* p = (StopTrack*)operator_new(0x18);
    if (p) {
        p->init();
        *(uint*)p = ((int)DAT_00428db0);
        p->zero = 0;
        p->value = -1.0f;
        p->inner.init();
        p->flag = 1;
        return p;
    }
    return 0;
}