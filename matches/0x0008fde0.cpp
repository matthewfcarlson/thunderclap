#include "compat/ptr.h"
extern "C" void* memset(void*, int, unsigned);
extern "C" int FUN_00266da0(int);
extern "C" void* FUN_0008d690(hulk_uintptr);
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
    int h = FUN_00266da0(c);
    unsigned n = mB * mA;
    mData = FUN_0008d690(n);
    memset(mData, 0xbb, n);
    unsigned w = (mB >> 5) + ((mB & 31) != 0);
    mBits = FUN_0008d690(w * 4);
    memset(mBits, 0, w * 4);
    FUN_00266da0(h);
}