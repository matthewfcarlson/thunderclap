extern "C" char DAT_0041944c[];
class PropSetStateByIndexTrack {
  public:
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    void Init();
};
class Factory {
  public:
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual PropSetStateByIndexTrack* vfunc_5();
};
extern void* __cdecl Allocate(unsigned int);
PropSetStateByIndexTrack* Factory::vfunc_5() {
    PropSetStateByIndexTrack* p = (PropSetStateByIndexTrack*)Allocate(0x18);
    if (p) {
        p->Init();
        p->a = ((int)DAT_0041944c);
        p->d = 0;
        p->e = -1;
        p->f = 0;
        p->c = 1;
        return p;
    }
    return 0;
}
