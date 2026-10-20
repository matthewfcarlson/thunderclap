#include "compat/ptr.h"
extern "C" void* Alloc(hulk_uintptr);
class Arena_1b6380 {
  public:
    unsigned int *mStart, *mFree, *mEnd;
    Arena_1b6380();
};
Arena_1b6380::Arena_1b6380() {
    mStart = 0;
    mFree = 0;
    mEnd = 0;
    unsigned int* p = (unsigned int*)Alloc(0x1000);
    mStart = p;
    if (p) {
        mFree = p;
        mEnd = (unsigned int*)((char*)p + 0x1000);
    } else {
        mFree = 0;
        mEnd = 0;
    }
    register int n = 0x100;
    do {
        unsigned int* q = mFree;
        if (q < mEnd) {
            mFree = q + 1;
            if (q)
                *q = 0;
        }
        q = mFree;
        if (q < mEnd) {
            mFree = q + 1;
            if (q)
                *q = 0;
        }
        q = mFree;
        if (q < mEnd) {
            mFree = q + 1;
            if (q)
                *q = 0;
        }
        q = mFree;
        if (q < mEnd) {
            mFree = q + 1;
            if (q)
                *q = 0;
        }
    } while (--n);
}