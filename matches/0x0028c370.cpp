extern "C" void* memset(void*, int, unsigned);
void* Alloc(unsigned n);
struct Allocator_28c370 { void* Alloc2(unsigned n, int f); };
class Base_28c370 {
  public:
    Base_28c370(int a, int b);
    virtual void f0();
    int pad[2];
    int m0;
    unsigned cnt;
};
class BoolChannel : public Base_28c370 {
  public:
    BoolChannel(int a, int b);
    virtual void f0();
    int pad2;
    unsigned* bits;
};
BoolChannel::BoolChannel(int a, int b) : Base_28c370(a, b) {
    int n = ((cnt - 1) >> 5) + 1;
    bits = 0;
    if (m0 == 0)
        bits = (unsigned*)Alloc(n * 4);
    else
        bits = (unsigned*)((Allocator_28c370*)m0)->Alloc2(n * 4, 3);
    memset(bits, 0, n * 4);
}
