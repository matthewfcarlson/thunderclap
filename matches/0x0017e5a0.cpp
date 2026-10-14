extern "C" char DAT_00417ad8[];
class MomentumXZAddTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    int pad;
    int c;
    int d;
    float x;
    float y;
    void Init();
};
extern "C" void* __cdecl Alloc(unsigned int);
class Factory_17e5a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual MomentumXZAddTrack* f5();
};
MomentumXZAddTrack* Factory_17e5a0::f5() {
    MomentumXZAddTrack* p = (MomentumXZAddTrack*)Alloc(0x18);
    if (p) {
        p->Init();
        p->x = -1.0f;
        p->y = -1.0f;
        *(volatile int*)p = ((int)DAT_00417ad8);
        p->d = 0;
        p->c = 1;
        return p;
    }
    return 0;
}
