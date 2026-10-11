// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::FileOpenByKeyRequest::vfunc_0 @ 0x00274ff0
struct Lock { virtual void lock(); virtual void unlock(); };
struct Resource { virtual void slot0(); virtual void release(); Lock guard; char pad[16]; int count; };
struct Allocator { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void free(void*); };
extern Allocator* DAT_0052a1e4;
extern char DAT_0052a1c8;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
inline void* operator new(unsigned int, void* p) { return p; }
namespace core {
struct Request { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct FileRequest : Request { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); int field4; Resource* resource; };
struct FileOpenByKeyRequest : FileRequest { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_6(); };
void* FileOpenByKeyRequest::vfunc_0(unsigned int flags) { new (this) FileRequest; resource->guard.lock(); --resource->count; resource->guard.unlock(); resource->release(); new (this) Request; if(flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); } return this; }
}
