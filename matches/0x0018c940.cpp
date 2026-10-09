// Same code shape as 0x00077d00 (propagated; names are from that function)
typedef unsigned int u32;
void* __cdecl FUN_0008d690(unsigned int);
struct TrackFactoryTemplate { u32 a,b,c,d,e,f; u32 vfunc_5(); };
struct CKeyPoseTrack { u32 init(); };
u32 TrackFactoryTemplate::vfunc_5() { void* p = FUN_0008d690(0x78); if (p) return ((CKeyPoseTrack*)p)->init(); return 0; }