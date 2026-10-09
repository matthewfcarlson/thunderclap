// Same code shape as 0x00075d20 (propagated; names are from that function)
typedef unsigned int u32;
struct CAutoTargetTrack {
    u32 initialize();
};
extern void* __cdecl alloc(unsigned int);
struct TrackFactoryTemplate {
    u32 vfunc_5();
};
u32 TrackFactoryTemplate::vfunc_5() {
    CAutoTargetTrack* p = (CAutoTargetTrack*)alloc(0x3c);
    if (p)
        return p->initialize();
    return 0;
}