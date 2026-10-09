extern "C" void* Alloc(unsigned int);
class Arena {
  public:
    unsigned int *mStart, *mFree, *mEnd;
    Arena();
};
Arena::Arena() {
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