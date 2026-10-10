// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026d210 @ 0x0026d210
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace core { struct IRefCount { virtual void f(); }; struct BaseObject { virtual void f(); }; struct MemoryTwoWayAllocator : IRefCount, BaseObject { int unknown; int unknown2; void *memory; int a,b,c; ~MemoryTwoWayAllocator(); }; }
extern "C" void __cdecl FUN_00267090(void *);
extern "C" int DAT_004cdbb0;
core::MemoryTwoWayAllocator::~MemoryTwoWayAllocator() { FUN_00267090(memory); memory = 0; a = 0; b = 0; c = 0; DAT_004cdbb0 = unknown; new (static_cast<BaseObject *>(this)) BaseObject; new (static_cast<IRefCount *>(this)) IRefCount; }