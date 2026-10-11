// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::FileOpenRequest::vfunc_0 @ 0x00274f50
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
struct Lock { virtual void lock(); virtual void unlock(); };
struct File { virtual void unused(); virtual void release(); Lock lockObject; char pad[16]; int requests; };
struct Guard { char data[4]; };
extern Guard DAT_0052a1c8;
struct Allocator { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void freeMemory(void*); };
extern Allocator* DAT_0052a1e4;
void __cdecl FUN_0026d850(Guard*);
void __cdecl FUN_0026d840(Guard*);
namespace core {
struct Request { virtual void* vfunc_0(unsigned flags); };
struct FileRequest : Request { int unknown; File* file; virtual void* vfunc_0(unsigned flags); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct FileOpenRequest : FileRequest { virtual void* vfunc_0(unsigned flags); virtual void vfunc_1(); virtual void vfunc_6(); };
void* FileOpenRequest::vfunc_0(unsigned flags) {
new (this) FileRequest;
file->lockObject.lock();
--file->requests;
file->lockObject.unlock();
file->release();
new (this) Request;
if (flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->freeMemory(this); FUN_0026d840(&DAT_0052a1c8); }
return this;
}
}