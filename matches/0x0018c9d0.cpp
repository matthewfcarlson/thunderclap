typedef unsigned int U32;
struct Obj { U32 run(); };
struct TrackFactoryTemplate { U32 vfunc_0(); U32 vfunc_1(); U32 vfunc_2(); U32 vfunc_3(); U32 vfunc_4(); virtual U32 vfunc_5(); };
extern void* operator new(unsigned int);
U32 TrackFactoryTemplate::vfunc_5() {
    Obj* p = (Obj*)operator new(0x98);
    if (p) return p->run();
    return 0;
}