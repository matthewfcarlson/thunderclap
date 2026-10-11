extern "C" char DAT_003fbfa4[];
struct CDriftTrack {
    unsigned int vptr;
    unsigned int pad4;
    int field8;
    unsigned int fieldc;
    float field10;
    unsigned int field14;
    float field18;
    void init();
};
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
void* TrackFactoryTemplate::vfunc_5() {
    CDriftTrack* p = (CDriftTrack*)operator_new(0x1c);
    if (p) {
        p->init();
        p->vptr = ((int)DAT_003fbfa4);
        p->fieldc = 0;
        p->field10 = -1.0f;
        p->field14 = 0;
        p->field18 = 1.0f;
        p->field8 = 1;
        return p;
    }
    return 0;
}