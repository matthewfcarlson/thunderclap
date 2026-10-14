extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b364[];
extern "C" char DAT_0042b36c[];
extern "C" char DAT_004cdbb0[];
typedef unsigned int u32_26cc00;
struct MemoryDlAllocator {
    volatile u32_26cc00 vptr;
    volatile u32_26cc00 vptr2;
    volatile u32_26cc00 member;
    void Init();
};
void MemoryDlAllocator::Init() {
    vptr = ((int)DAT_0042b36c);
    vptr2 = ((int)DAT_0042b364);
    *(volatile u32_26cc00*)((int)DAT_004cdbb0) = member;
    vptr2 = ((int)DAT_0042af64);
    vptr = ((int)DAT_003f6098);
}