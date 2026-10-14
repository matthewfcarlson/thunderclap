extern void __cdecl thunk_FUN_00267090(int);
extern void* __cdecl FUN_0008d6d0(int);
extern void __cdecl FUN_000fb690(void*, const short*, int);
class Obj_f79a0 {
  public:
    char pad0[0x10];
    void* mData;
    int mOther;
    char pad18[8];
    int mState;
    void Set(const short* text, int unused);
};
void Obj_f79a0::Set(const short* text, int unused) {
    mState = -1;
    if (mData != 0) {
        thunk_FUN_00267090((int)mData);
        mData = 0;
    }
    if (text != 0) {
        int n = 0;
        while (text[n] != 0)
            ++n;
        mData = FUN_0008d6d0(n * 2 + 2);
        if (mData == 0)
            return;
        FUN_000fb690(mData, text, n + 1);
    }
    mOther = -1;
}