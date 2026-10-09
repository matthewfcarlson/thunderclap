extern "C" void* memset(void*, int, unsigned);
void* Alloc(unsigned n);
void* __stdcall Alloc2(unsigned n, int f);
class Base {
  public:
    Base(int a, int b);
    virtual void f0();
    int pad[2];
    int m0;
    unsigned cnt;
};
class BoolChannel : public Base {
  public:
    BoolChannel(int a, int b);
    virtual void f0();
    int pad2;
    unsigned* bits;
};
BoolChannel::BoolChannel(int a, int b) : Base(a, b) {
    int n = ((cnt - 1) >> 5) + 1;
    bits = 0;
    if (m0 == 0)
        bits = (unsigned*)Alloc(n * 4);
    else
        bits = (unsigned*)Alloc2(n * 4, 3);
    memset(bits, 0, n * 4);
}
