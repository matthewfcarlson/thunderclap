typedef unsigned int u32_6f340;
struct TrackFactoryTemplate {
    u32_6f340 vfunc_0();
    u32_6f340 vfunc_1();
    u32_6f340 vfunc_2();
    u32_6f340 vfunc_3();
    u32_6f340 vfunc_4();
    u32_6f340 vfunc_5();
};
struct Helper_6f340 {
    u32_6f340 run();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
u32_6f340 TrackFactoryTemplate::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_6f340*)p)->run();
    return 0;
}