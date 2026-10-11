// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::MemoryTwoWayAllocator::vfunc_2 @ 0x0026d3a0
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* storage) { return storage; }
extern "C" void __cdecl FUN_00267090(void*);
extern "C" void __cdecl FUN_00266f00(unsigned int, void*);
extern "C" unsigned int DAT_004cdbb0;
namespace core {
struct IRefCount { virtual void vfunc_0(); virtual void vfunc_1(); };
struct BaseObject { virtual void vfunc_0_adj4(); };
struct MemoryTwoWayAllocator : IRefCount, BaseObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual MemoryTwoWayAllocator* vfunc_2(unsigned char);
 virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
 virtual void vfunc_0_adj4();
 unsigned int allocator, reserved; void* memory; unsigned int low, high, end;
};
MemoryTwoWayAllocator* MemoryTwoWayAllocator::vfunc_2(unsigned char flags) {
 void* block = memory;
 new (this) MemoryTwoWayAllocator;
 FUN_00267090(block);
 memory = 0; low = high = end = 0;
 DAT_004cdbb0 = allocator;
 new (static_cast<BaseObject*>(this)) BaseObject;
 new (static_cast<IRefCount*>(this)) IRefCount;
 if (flags & 1) FUN_00266f00(DAT_004cdbb0, this);
 return this;
}
}
