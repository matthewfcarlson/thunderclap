extern void* operator new(unsigned int);
class Track {
  public:
    int make();
};
class Factory_1aa780 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int vfunc_5();
};
int Factory_1aa780::vfunc_5() {
    Track* p = (Track*)operator new(0x198);
    if (p)
        return p->make();
    return 0;
}