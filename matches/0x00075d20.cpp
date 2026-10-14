typedef unsigned int u32_75d20;
struct CAutoTargetTrack {
    u32_75d20 initialize();
};
extern void* __cdecl alloc(unsigned int);
struct TrackFactoryTemplate {
    u32_75d20 vfunc_5();
};
u32_75d20 TrackFactoryTemplate::vfunc_5() {
    CAutoTargetTrack* p = (CAutoTargetTrack*)alloc(0x3c);
    if (p)
        return p->initialize();
    return 0;
}