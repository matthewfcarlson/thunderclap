namespace core {
struct IMemoryAllocator {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned);
};
struct IRefCount {
    virtual void vfunc_2(unsigned);
};
struct __declspec(dllexport) MemoryDlAllocator : IMemoryAllocator, IRefCount {
    void vfunc_2(unsigned);
};
void MemoryDlAllocator::vfunc_2(unsigned flags) {
    IMemoryAllocator::vfunc_2(flags);
}
} // namespace core