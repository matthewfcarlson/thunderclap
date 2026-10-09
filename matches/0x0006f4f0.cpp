struct TrackFactoryTemplate { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual int vfunc_5(); };
struct Thing { int init(); };
void* operator new(unsigned int);
int TrackFactoryTemplate::vfunc_5() {
    Thing* p = (Thing*)operator new(0x14);
    if (p) return p->init();
    return 0;
}
