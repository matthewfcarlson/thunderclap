// Same code shape as 0x0024e6f0 (propagated; names are from that function)
typedef unsigned int u32;
extern void* __cdecl Acquire(void*);
extern char gPool;
extern const char gName[];
extern int gVtable;
class audio_SeqEventNestTrackType { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void* f3(); };
class NameObj { public: void set(const char*, int); };
class NestTrack { public: u32 vf; char pad[4]; NameObj name; void init(); };
void* audio_SeqEventNestTrackType::f3() {
 NestTrack* p=(NestTrack*)Acquire(&gPool);
 if(p) { p->init(); p->vf=(u32)&gVtable; p->name.set(gName,2); return p; }
 return 0;
}