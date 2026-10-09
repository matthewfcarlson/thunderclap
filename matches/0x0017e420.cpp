class DriftTrack {
  public:
    volatile int a[8];
};
void* __cdecl Alloc(unsigned int);
class InitObj {
  public:
    void Init();
};
class TrackFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual DriftTrack* f5();
};
DriftTrack* TrackFactory::f5() {
    DriftTrack* p = (DriftTrack*)Alloc(0x20);
    if (p) {
        ((InitObj*)p)->Init();
        p->a[3] = 0;
        p->a[0] = 0x417a78;
        p->a[4] = (int)0xbf800000;
        p->a[5] = 0;
        p->a[6] = 0;
        p->a[7] = 0;
        p->a[2] = 1;
        return p;
    }
    return 0;
}