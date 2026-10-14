typedef unsigned int U32_18c9d0;
struct Obj_18c9d0 {
    U32_18c9d0 run();
};
struct TrackFactoryTemplate {
    U32_18c9d0 vfunc_0();
    U32_18c9d0 vfunc_1();
    U32_18c9d0 vfunc_2();
    U32_18c9d0 vfunc_3();
    U32_18c9d0 vfunc_4();
    virtual U32_18c9d0 vfunc_5();
};
extern void* operator new(unsigned int);
U32_18c9d0 TrackFactoryTemplate::vfunc_5() {
    Obj_18c9d0* p = (Obj_18c9d0*)operator new(0x98);
    if (p)
        return p->run();
    return 0;
}