// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::DriveFindCloseRequest::vfunc_0 @ 0x00275b60
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
namespace core {
struct Lock { virtual void lock(); virtual void unlock(); };
struct Drive { virtual void s0(); virtual void release(); Lock mutex; char pad[12]; int count; };
struct Request { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct DriveRequest : Request { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); int field4; Drive* drive; };
struct DriveFindCloseRequest : DriveRequest { virtual void* vfunc_0(unsigned int); virtual void vfunc_1(); virtual void vfunc_4(); virtual void vfunc_6(); };
}
struct Allocator { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void free(void*); };
extern char DAT_0052a1c8;
extern Allocator* DAT_0052a1e4;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
void* core::DriveFindCloseRequest::vfunc_0(unsigned int flags) {
 new (this) DriveRequest;
 drive->mutex.lock();
 --drive->count;
 drive->mutex.unlock();
 drive->release();
 new (this) Request;
 if (flags & 1) { FUN_0026d850(&DAT_0052a1c8); DAT_0052a1e4->free(this); FUN_0026d840(&DAT_0052a1c8); }
 return this;
}
