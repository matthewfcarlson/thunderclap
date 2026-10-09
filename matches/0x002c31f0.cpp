// Same code shape as 0x00267220 (propagated; names are from that function)
class MemoryAllocatorMalloc {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4(void*);
};
void thunk(void*);
void MemoryAllocatorMalloc::vfunc_4(void* p) {
    thunk(p);
}