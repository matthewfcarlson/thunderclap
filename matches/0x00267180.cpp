extern char vftable;
void InitAllocator();
struct MemoryAllocatorMalloc {
    void* vptr;
    MemoryAllocatorMalloc* Init();
};
MemoryAllocatorMalloc* MemoryAllocatorMalloc::Init() {
    vptr = &vftable;
    InitAllocator();
    return this;
}