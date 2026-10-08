typedef unsigned int u32;
void __cdecl AllocHelper(u32, u32);
class MemoryAllocatorMalloc {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
 virtual void vfunc_6(u32 a, u32 b);
 virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12();
};
void MemoryAllocatorMalloc::vfunc_6(u32 a, u32 b) { AllocHelper(a, b); }