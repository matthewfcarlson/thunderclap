// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::DriveMediaRequest::vfunc_0 @ 0x00275780
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace core {
struct Request { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct Lock_275780 { virtual void lock(); virtual void unlock(); };
struct Device_275780 { virtual void s0(); virtual void release(); Lock_275780 lock; char pad[12]; int count; };
struct DriveRequest : Request { virtual void vfunc_0(); virtual void vfunc_1(); int f4; Device_275780* device; };
struct DriveMediaRequest : DriveRequest { virtual void* vfunc_0(unsigned int flags); };
}
struct Allocator { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void free(void*); };
extern Allocator* DAT_0052a1e4;
extern char DAT_0052a1c8;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
void* core::DriveMediaRequest::vfunc_0(unsigned int flags) {
 new (this) DriveRequest;
 device->lock.lock(); --device->count; device->lock.unlock(); device->release();
 new (this) Request;
 if(flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); }
 return this;
}
