extern "C" char DAT_004144b0[];
class HitPushbackTrack {
  public:
    int vptr;
    int x04;
    int x08;
    int x0c;
    float x10;
    float x14;
    float x18;
    unsigned char x1c;
    char x1d[3];
    int x20;
    int x24;
    int x28;
    int x2c;
    int x30;
    void init();
};
class Factory {
  public:
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual HitPushbackTrack* vfunc_5();
};
extern HitPushbackTrack* __cdecl alloc(unsigned int);
HitPushbackTrack* Factory::vfunc_5() {
    HitPushbackTrack* p = alloc(0x34);
    if (p) {
        p->init();
        p->x10 = -1.0f;
        p->x18 = -1.0f;
        p->x0c = 0;
        p->x1c = 0;
        p->x20 = 0;
        p->x24 = 0;
        p->x2c = 0;
        p->x30 = 0;
        p->vptr = ((int)DAT_004144b0);
        p->x14 = 1.0f;
        p->x28 = -5;
        return p;
    }
    return 0;
}