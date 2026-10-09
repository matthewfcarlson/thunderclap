class PropDropTrack {
  public:
    void Init();
    int vt;
    int pad;
    int e;
    int c;
    int d;
};
extern void* operator_new(unsigned int);
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    PropDropTrack* vfunc_5();
};
PropDropTrack* Factory::vfunc_5() {
    PropDropTrack* p = (PropDropTrack*)operator_new(0x14);
    if (p) {
        p->Init();
        p->vt = 0x41935c;
        p->c = 0;
        p->d = -1;
        p->e = 1;
        return p;
    }
    return 0;
}
