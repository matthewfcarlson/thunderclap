class Thing_1c7720 {
  public:
    virtual void A();
    virtual void B(void*);
    virtual void Clear(void*);
    char pad[8];
    int mC;
    int mCount;
    void** mItems;
    void Reset();
};
void Thing_1c7720::Reset() {
    int i = 0;
    if (mCount >= 0) {
        do {
            void* p = mItems[i];
            if (p) {
                Clear(p);
                mItems[i] = 0;
            }
            ++i;
        } while (i <= mCount);
    }
    mC = 0;
    mCount = -1;
}