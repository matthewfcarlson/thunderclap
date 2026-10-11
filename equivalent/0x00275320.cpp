// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::FileWriteRequest::vfunc_0 @ 0x00275320
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
struct Lock { virtual void lock(); virtual void unlock(); };
struct File { virtual void slot0(); virtual void slot1(); Lock guard; char pad[16]; int count; };
extern char DAT_0052a1c8;
struct Allocator { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void free(void*); };
extern Allocator* DAT_0052a1e4;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
namespace core {
struct Request { virtual void* vfunc_0(unsigned); };
struct FileRequest : Request { unsigned unknown; File* file; virtual void* vfunc_0(unsigned); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct FileWriteRequest : FileRequest { virtual void* vfunc_0(unsigned); virtual void vfunc_1(); virtual void vfunc_6(); };
void* FileWriteRequest::vfunc_0(unsigned flags) {
 new(this) FileRequest;
 file->guard.lock();
 --file->count;
 file->guard.unlock();
 file->slot1();
 new(this) Request;
 if(flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); }
 return this;
}
}
