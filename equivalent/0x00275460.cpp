// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::FileGetPositionRequest::vfunc_0 @ 0x00275460
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) throw() { return p; }
struct Lock_275460 { virtual void acquire(); virtual void release(); };
struct File { virtual void slot0(); virtual void release(); Lock_275460 lock; char padding[16]; int count; };
struct Allocator { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void free(void*); };
extern char DAT_0052a1c8;
extern Allocator* DAT_0052a1e4;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
namespace core {
struct Request { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct FileRequest : Request { int field4; File* file; virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct FileGetPositionRequest : FileRequest { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_6(); };
void* FileGetPositionRequest::vfunc_0(unsigned int flags) {
new (this) FileRequest;
file->lock.acquire();
--file->count;
file->lock.release();
file->release();
new (this) Request;
if (flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); }
return this;
}
}
