typedef unsigned int u32_77d00;
void* __cdecl FUN_0008d690(unsigned int);
struct TrackFactoryTemplate {
    u32_77d00 a, b, c, d, e, f;
    u32_77d00 vfunc_5();
};
struct CKeyPoseTrack {
    u32_77d00 init();
};
u32_77d00 TrackFactoryTemplate::vfunc_5() {
    void* p = FUN_0008d690(0x78);
    if (p)
        return ((CKeyPoseTrack*)p)->init();
    return 0;
}