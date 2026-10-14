// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::DriveFormatRequest::vfunc_0 @ 0x00275810
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct Lock_275810 { virtual void FUN_0(); virtual void FUN_1(); };
struct Drive { virtual void FUN_2(); virtual void FUN_3(); Lock_275810 lock; char pad[12]; int count; };
struct Allocator { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void free(void*); };
extern char DAT_0052a1c8;
extern Allocator* DAT_0052a1e4;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
namespace core {
struct Request { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); int field4; Drive* drive; };
struct DriveRequest : Request { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct DriveFormatRequest : DriveRequest { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_4(); virtual void vfunc_6(); };
void* DriveFormatRequest::vfunc_0(unsigned int flags) {
 new(this) DriveRequest;
 drive->lock.FUN_0();
 --drive->count;
 drive->lock.FUN_1();
 drive->FUN_3();
 new(this) Request;
 if(flags&1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); }
 return this;
}
}
