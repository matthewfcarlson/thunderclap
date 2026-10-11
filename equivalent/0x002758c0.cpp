// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::DriveCreateDirectoryRequest::vfunc_0 @ 0x002758c0
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
struct Lock { virtual void lock(); virtual void unlock(); };
struct Drive { virtual void slot0(); virtual void release(); Lock lockObject; char pad[12]; int references; };
struct Allocator { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void free(void*); };
extern char DAT_0052a1c8;
extern Allocator* DAT_0052a1e4;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
namespace core {
struct Request { virtual void* vfunc_0(unsigned); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct DriveRequest : Request { int unknown; Drive* drive; virtual void* vfunc_0(unsigned); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct DriveCreateDirectoryRequest : DriveRequest { virtual void* vfunc_0(unsigned); virtual void vfunc_1(); virtual void vfunc_5(); virtual void vfunc_6(); };
void* DriveCreateDirectoryRequest::vfunc_0(unsigned flags) {
 new (this) DriveRequest;
 drive->lockObject.lock();
 --drive->references;
 drive->lockObject.unlock();
 drive->release();
 new (this) Request;
 if (flags & 1) {
 FUN_0026d850(&DAT_0052a1c8);
 DAT_0052a1e4->free(this);
 FUN_0026d840(&DAT_0052a1c8);
 }
 return this;
}
}
