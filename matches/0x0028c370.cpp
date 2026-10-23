#include "compat/ptr.h"
extern "C" void* memset(void*, int, unsigned);
void* FUN_0008d6d0(hulk_uintptr n);
struct Allocator_28c370 { void* Alloc2(unsigned n, int f); };
class SimpleChannel_28c370 {
  public:
    SimpleChannel_28c370(int a, int b);
    virtual void f0();
    int pad[2];
    hulk_intptr m0;
    unsigned cnt;
};
class BoolChannel : public SimpleChannel_28c370 {
  public:
    BoolChannel(int a, int b);
    virtual void f0();
    int pad2;
    unsigned* bits;
};
BoolChannel::BoolChannel(int a, int b) : SimpleChannel_28c370(a, b) {
    int n = ((cnt - 1) >> 5) + 1;
    bits = 0;
    if (m0 == 0)
        bits = (unsigned*)FUN_0008d6d0(n * 4);
    else
        bits = (unsigned*)((Allocator_28c370*)m0)->Alloc2(n * 4, 3);
    memset(bits, 0, n * 4);
}
