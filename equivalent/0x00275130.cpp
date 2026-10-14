// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::FileCloseRequest::vfunc_0 @ 0x00275130
typedef unsigned size_t;
inline void* operator new(size_t, void* p) { return p; }
struct Guard_275130 { char data[4]; };
extern Guard_275130 DAT_0052a1c8;
void __cdecl FUN_0026d850(Guard_275130*);
void __cdecl FUN_0026d840(Guard_275130*);
struct Allocator { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void free(void*); };
extern Allocator* DAT_0052a1e4;
namespace core {
struct Lock_275130 { virtual void lock(); virtual void unlock(); };
struct File { virtual void slot0(); virtual void release(); Lock_275130 lock; char pad[16]; unsigned count; };
struct Request { virtual void* vfunc_0(unsigned); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct FileRequest : Request { unsigned field4; File* file; virtual void* vfunc_0(unsigned); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct FileCloseRequest : FileRequest { virtual void* vfunc_0(unsigned flags); };
void* FileCloseRequest::vfunc_0(unsigned flags) {
 new (this) FileRequest;
 file->lock.lock();
 --file->count;
 file->lock.unlock();
 file->release();
 new (this) Request;
 if (flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); }
 return this;
}
}
