extern "C" char DAT_0041956c[];
extern "C" void* Alloc(unsigned int);
class Track {
  public:
    Track();
    virtual void a();
    virtual void b();
    virtual void c();
};
class PropDamageTrack : public Track {
  public:
    int x4;
    int x8;
    int xc;
    int x10;
    int x14;
};
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual PropDamageTrack* f5();
};
PropDamageTrack* Factory::f5() {
    PropDamageTrack* p = (PropDamageTrack*)Alloc(0x18);
    if (p) {
        p->Track::Track();
        *(volatile unsigned int*)p = ((int)DAT_0041956c);
        p->xc = 0;
        p->x10 = 0;
        p->x14 = 0;
        p->x8 = 1;
        return p;
    }
    return 0;
}