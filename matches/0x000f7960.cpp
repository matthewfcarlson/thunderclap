typedef unsigned int U32_f7960;
void ReleaseThing(U32_f7960);
class Thing_f7960 {
  public:
    char pad[0x0c];
    U32_f7960 mSecond;
    U32_f7960 mFirst;
    void Clear();
};
void Thing_f7960::Clear() {
    if (mFirst) {
        ReleaseThing(mFirst);
        mFirst = 0;
    }
    if (mSecond) {
        ReleaseThing(mSecond);
        mSecond = 0;
    }
}