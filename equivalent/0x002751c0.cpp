// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::FileCommitRequest::vfunc_0 @ 0x002751c0
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
struct Lock { virtual void lock(); virtual void unlock(); };
struct File { virtual void slot0(); virtual void release(); Lock mutex; char pad[16]; int count; };
struct Alloc { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void free(void*); };
extern char DAT_0052a1c8;
extern Alloc* DAT_0052a1e4;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
namespace core {
struct Request { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct FileRequest : Request { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); int field4; File* file; };
struct FileCommitRequest : FileRequest { virtual void* vfunc_0(unsigned int flags); };
void* FileCommitRequest::vfunc_0(unsigned int flags) {
 new (this) FileRequest;
 file->mutex.lock();
 --file->count;
 file->mutex.unlock();
 file->release();
 new (this) Request;
 if(flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); }
 return this;
}
}
