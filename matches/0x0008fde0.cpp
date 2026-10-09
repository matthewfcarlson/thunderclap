extern "C" void* memset(void*, int, unsigned);
int Push(int);
void* Alloc(unsigned);
class CStaticAllocator {
  public:
    virtual void f0();
    CStaticAllocator(unsigned a, unsigned b, int c, int d);
    unsigned mA, mB;
    int mC;
    void* mData;
    void* mBits;
    int mZ;
};
CStaticAllocator::CStaticAllocator(unsigned a, unsigned b, int c, int d) {
    mA = a;
    mB = b;
    mC = d;
    mZ = 0;
    int h = Push(c);
    unsigned n = mB * mA;
    mData = Alloc(n);
    memset(mData, 0xbb, n);
    unsigned w = (mB >> 5) + ((mB & 31) != 0);
    mBits = Alloc(w * 4);
    memset(mBits, 0, w * 4);
    Push(h);
}