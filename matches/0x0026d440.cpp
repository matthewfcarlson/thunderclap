class MemoryTwoWayAllocator { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void vfunc_6(unsigned int, unsigned int); void helper(unsigned int, unsigned int); };
void MemoryTwoWayAllocator::vfunc_6(unsigned int x, unsigned int y) { if (y <= 4) y = 4; helper(x, y); }
