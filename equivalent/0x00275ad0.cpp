// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::DriveFindNextRequest::vfunc_0 @ 0x00275ad0
typedef unsigned int uint_275ad0;
inline void* operator new(unsigned int, void* p) throw() { return p; }
struct Lock_275ad0 { virtual void enter(); virtual void leave(); };
struct Owner_275ad0 { virtual void slot0(); virtual void release(); Lock_275ad0 lock; char pad[12]; uint_275ad0 count; };
struct Allocator { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void free(void*); };
extern char DAT_0052a1c8;
extern Allocator* DAT_0052a1e4;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
namespace core {
struct Request { virtual void* vfunc_0(uint_275ad0); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); uint_275ad0 field4; Owner_275ad0* owner; };
struct DriveRequest : Request { virtual void* vfunc_0(uint_275ad0); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct DriveFindNextRequest : DriveRequest { virtual void* vfunc_0(uint_275ad0); virtual void vfunc_1(); virtual void vfunc_6(); };
void* DriveFindNextRequest::vfunc_0(uint_275ad0 flags) {
new(this) DriveRequest;
owner->lock.enter(); --owner->count; owner->lock.leave(); owner->release();
new(this) Request;
if(flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); }
return this;
}
}
