// Same code shape as 0x0006f220 (propagated; names are from that function)
typedef unsigned int u32;
extern void* __cdecl Alloc(unsigned int);
struct InitObj { u32 Init(); };
class TrackFactoryTemplate {
public:
 virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e();
 virtual u32 vfunc_5();
};
u32 TrackFactoryTemplate::vfunc_5() {
 void* p = Alloc(0x60);
 if (p) return ((InitObj*)p)->Init();
 return 0;
}