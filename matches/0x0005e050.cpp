class CClearHitRecordsTrack { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual int vfunc_12(int); virtual void v13(); };
class Helper { public: int go(int); };
extern "C" void* __cdecl FUN_0008d690(unsigned int);
int CClearHitRecordsTrack::vfunc_12(int a) { void* p = FUN_0008d690(0x20); if (p) return ((Helper*)p)->go(a); return 0; }