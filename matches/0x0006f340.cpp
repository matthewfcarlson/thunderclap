typedef unsigned int u32;
struct TrackFactoryTemplate { u32 vfunc_0(); u32 vfunc_1(); u32 vfunc_2(); u32 vfunc_3(); u32 vfunc_4(); u32 vfunc_5(); };
struct Helper { u32 run(); };
extern "C" void* __cdecl FUN_0008d690(unsigned int);
u32 TrackFactoryTemplate::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p) return ((Helper*)p)->run();
    return 0;
}