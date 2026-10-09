typedef unsigned int U32;
void ReleaseThing(U32);
class Thing {
public:
    char pad[0x0c];
    U32 mSecond;
    U32 mFirst;
    void Clear();
};
void Thing::Clear() {
    if (mFirst) {
        ReleaseThing(mFirst);
        mFirst = 0;
    }
    if (mSecond) {
        ReleaseThing(mSecond);
        mSecond = 0;
    }
}