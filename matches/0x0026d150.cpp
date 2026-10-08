class MemoryTwoWayAllocator { char pad[0x10]; int a; int b; public: int vfunc_11(); };
int MemoryTwoWayAllocator::vfunc_11() { return b - a; }