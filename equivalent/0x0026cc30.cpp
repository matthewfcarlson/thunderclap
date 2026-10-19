// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// core::MemoryDlAllocator::vfunc_0_adj4 @ 0x0026cc30
namespace core {
struct MemoryDlAllocator {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned flags);
    void vfunc_0_adj4(unsigned flags);
};
void MemoryDlAllocator::vfunc_0_adj4(unsigned flags) {
    MemoryDlAllocator* owner = reinterpret_cast<MemoryDlAllocator*>(reinterpret_cast<char*>(this) - 4);
    owner->MemoryDlAllocator::vfunc_2(flags);
}
}