// Same code shape as 0x0006f340 (propagated; names are from that function)
typedef unsigned int u32_6fe80;
struct TrackFactoryTemplate {
    u32_6fe80 vfunc_0();
    u32_6fe80 vfunc_1();
    u32_6fe80 vfunc_2();
    u32_6fe80 vfunc_3();
    u32_6fe80 vfunc_4();
    u32_6fe80 vfunc_5();
};
struct Helper_6fe80 {
    u32_6fe80 run();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
u32_6fe80 TrackFactoryTemplate::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_6fe80*)p)->run();
    return 0;
}