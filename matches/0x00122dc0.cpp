// Same code shape as 0x00075d20 (propagated; names are from that function)
typedef unsigned int u32_122dc0;
struct CAutoTargetTrack {
    u32_122dc0 initialize();
};
extern void* __cdecl alloc(unsigned int);
struct TrackFactoryTemplate {
    u32_122dc0 vfunc_5();
};
u32_122dc0 TrackFactoryTemplate::vfunc_5() {
    CAutoTargetTrack* p = (CAutoTargetTrack*)alloc(0x3c);
    if (p)
        return p->initialize();
    return 0;
}