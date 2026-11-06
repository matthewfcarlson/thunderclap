// core::MemoryAllocatorMalloc::vfunc_6 (slot 6: allocate aligned)
extern "C" void* __cdecl FUN_00270570(int size, unsigned alignment);
class MemoryAllocatorMalloc_267230 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void* vfunc_6(int size, unsigned alignment);
};
void* MemoryAllocatorMalloc_267230::vfunc_6(int size, unsigned alignment) {
    return FUN_00270570(size, alignment);
}
