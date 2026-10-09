class Allocator {
  public:
    virtual void Fn();
};
Allocator* g_allocator;
void InitAllocator() {
    g_allocator = (Allocator*)0x429254;
}