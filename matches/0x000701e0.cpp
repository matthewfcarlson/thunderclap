// Same code shape as 0x0006f4f0 (propagated; names are from that function)
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int vfunc_5();
};
struct Thing_701e0 {
    int init();
};
void* operator new(unsigned int);
int TrackFactoryTemplate::vfunc_5() {
    Thing_701e0* p = (Thing_701e0*)operator new(0x14);
    if (p)
        return p->init();
    return 0;
}
