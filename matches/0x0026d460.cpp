// Same code shape as 0x0026d420 (propagated; names are from that function)
class MemoryTwoWayAllocator { public: char pad[0x1c]; unsigned int mLimit; int mFirst; int mSecond; void vfunc_4(unsigned int); };
void MemoryTwoWayAllocator::vfunc_4(unsigned int n) { if (n) { if (n < mLimit) --mFirst; else --mSecond; } }