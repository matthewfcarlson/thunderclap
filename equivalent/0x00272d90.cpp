// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::Drive::vfunc_2 @ 0x00272d90
typedef unsigned size_t;
inline void* operator new(size_t, void* p) { return p; }
extern unsigned DAT_004cdbb0;
void __cdecl FUN_00266f00(unsigned, void*);
struct Cleanup { void FUN_00277540(); };
namespace core {
struct IRefCount { virtual void vfunc_0(); virtual void vfunc_1(); virtual IRefCount* vfunc_2(unsigned); };
struct BaseObject { virtual void vfunc_0(); unsigned allocator; };
struct SafeRefCount { virtual void s0(); virtual void s1(); virtual void s2(); };
struct Drive : IRefCount, BaseObject, SafeRefCount { unsigned reserved; Cleanup cleanup; virtual void vfunc_0(); virtual void vfunc_1(); virtual Drive* vfunc_2(unsigned flags); virtual void s0(); virtual void s1(); virtual void s2(); };
Drive* Drive::vfunc_2(unsigned flags) { new(this) Drive; cleanup.FUN_00277540(); new(static_cast<SafeRefCount*>(this)) SafeRefCount; DAT_004cdbb0=allocator; new(static_cast<BaseObject*>(this)) BaseObject; new(static_cast<IRefCount*>(this)) IRefCount; if(flags&1) FUN_00266f00(DAT_004cdbb0,this); return this; }
}
