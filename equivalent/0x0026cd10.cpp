// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 4/4)
// core::MemoryDlAllocator::vfunc_4 @ 0x0026cd10
namespace core {
struct MemoryDlAllocator {
    void *vtable;
    void *secondaryVtable;
    unsigned char padding[4];
    unsigned int heapStart;
    unsigned int heapEnd;
    unsigned int heapLimit;
    unsigned int resetValue;
    unsigned int data[0x11d];
    unsigned int allocationCount;
    unsigned int availableBytes;
    void vfunc_4(void *p);
};
}
extern unsigned int DAT_005283a0;
extern unsigned int DAT_005283a4;
extern unsigned int DAT_005283a8;
extern unsigned int *DAT_005283ac;
extern unsigned int *DAT_0052839c;
void __cdecl FUN_0026bd80(void *);
void core::MemoryDlAllocator::vfunc_4(void *p) {
    if (!p) return;
    DAT_005283a0 = heapStart;
    DAT_005283a8 = heapEnd;
    DAT_005283ac = &resetValue;
    DAT_005283a4 = heapLimit;
    unsigned int size = ((unsigned int *)p)[-1] & ~3u;
    DAT_0052839c = data;
    availableBytes -= size;
    FUN_0026bd80(p);
    --allocationCount;
    if (allocationCount == 0) {
        resetValue = heapStart;
        for (int i = 0; i < 0x11d; ++i) data[i] = 0;
    }
}