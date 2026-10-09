typedef unsigned int u32;
struct MemoryDlAllocator { volatile u32 vptr; volatile u32 vptr2; volatile u32 member; void Init(); };
void MemoryDlAllocator::Init() {
 vptr=0x42b36c;
 vptr2=0x42b364;
 *(volatile u32*)0x4cdbb0=member;
 vptr2=0x42af64;
 vptr=0x3f6098;
}