extern char vftable_267180;
void InitAllocator();
struct MemoryAllocatorMalloc {
    void* vptr;
    MemoryAllocatorMalloc* Init();
};
MemoryAllocatorMalloc* MemoryAllocatorMalloc::Init() {
    vptr = &vftable_267180;
    InitAllocator();
    return this;
}