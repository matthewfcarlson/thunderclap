extern "C" char DAT_003fc148[];
class CDeathTrack {
  public:
    int pad[4];
    void init();
};
extern void* __cdecl operator_new(unsigned int);
class TrackFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CDeathTrack* f5();
};
CDeathTrack* TrackFactoryTemplate::f5() {
    CDeathTrack* p = (CDeathTrack*)operator_new(0x10);
    if (p) {
        p->init();
        *(unsigned long*)p = ((int)DAT_003fc148);
        *(unsigned long*)((char*)p + 0xc) = 0;
        return p;
    }
    return 0;
}