// Same code shape as 0x0006f100 (propagated; names are from that function)
struct Allocated_6ffa0 {
    int Finish();
};
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int vfunc_5();
};
extern void* Allocate(unsigned int);
int TrackFactoryTemplate::vfunc_5() {
    Allocated_6ffa0* p = (Allocated_6ffa0*)Allocate(0x10);
    if (p)
        return p->Finish();
    return 0;
}