extern "C" char DAT_00429254[];
class Allocator {
  public:
    virtual void Fn();
};
extern "C" Allocator* DAT_004cc200;
void InitAllocator() {
    DAT_004cc200 = (Allocator*)((int)DAT_00429254);
}