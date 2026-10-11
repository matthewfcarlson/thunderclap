extern "C" char DAT_00429254[];
class Allocator {
  public:
    virtual void Fn();
};
Allocator* g_allocator;
void InitAllocator() {
    g_allocator = (Allocator*)((int)DAT_00429254);
}