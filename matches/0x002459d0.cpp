struct Table_2459d0 {
    int a, b;
    char(__cdecl* fn)(void*, void*, int, int);
};
class Buffer_2459d0 {
  public:
    virtual void F0();
    virtual void F1();
    char pad[0x7c];
    Table_2459d0* mOther;
    int mStart;
    unsigned int mEnd;
    int mIndex, mPad1, mPad2, mPad3, mDone;
};
void Buffer_2459d0::F0() {
    int n = mEnd + mStart;
    char* p = (char*)this + (n & 0x7f);
    Table_2459d0* q = mOther;
    if (q->fn(q, p, 1, 1)) {
        ++mDone;
        if (mEnd < 0x80)
            ++mEnd;
        else {
            mStart = (mStart + 1) & 0x7f;
            ++mIndex;
        }
    }
}